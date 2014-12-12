#include <stdio.h>
#include "TimeTabling.h"
#include "TimeTablingClassList.h"
#include "Node.h"
#include "RedBlackTree.h"
#include "ErrorCode.h"
#include "CustomAssertions.h"
#include "Rotations.h"
#include "InitNode.h"

Class class[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS];
	
char *getCourseName(Course newCourse){
	if(newCourse.courseName != NULL)
    return newCourse.courseName;
}

char *getCourseCode(Course newCourse){

	if(newCourse.courseCode != NULL)
    return newCourse.courseCode;
}

// int getTotalStudentsInCourse(Class *newClass) {
  // if(newClass->group->groupSize != 0)
      // return newClass->group->groupSize;  
// }

// int getVenueSize(Class *newClass) {
  // if(newClass->venue->sizeOfVenue != 0)
    // return newClass->venue->sizeOfVenue;
// }

// constraints try

int checkIfTutionOverloadedInSingleDay(Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS], int day){
	
	int time, venue, i, violationCounter = 0;
	Counter counter[(sizeof(group)/sizeof(Group))] = {{.tutorialHours = 0, .lectureHours = 0},
																										{.tutorialHours = 0, .lectureHours = 0},
																										{.tutorialHours = 0, .lectureHours = 0},
																										{.tutorialHours = 0, .lectureHours = 0}};

  for(venue = 0 ; venue < MAX_VENUE ; venue++){
    for(time = 0 ; time < MAX_TIME_SLOTS ; time++){
      for(i = 0 ; i < MAX_TIME_SLOTS ; i++){
        if(newClass[venue][day][time].course && newClass[venue][day][time].course == &course[i]){
          if(newClass[venue][day][time].typeOfClass == 'l')
            counter[i].lectureHours+=1;
          else if(newClass[venue][day][time].typeOfClass == 't')
            counter[i].tutorialHours+=1;
          else if(newClass[venue][day][time].typeOfClass == 'p')
            counter[i].practicalHours+=1;	
        }
      }
    }	
  }

  for( i = 0; i < (sizeof(group)/ sizeof(Group)) ; i++){
    if(counter[i].lectureHours > course[i].hoursOfLecture)
      violationCounter+= counter[i].lectureHours - course[i].hoursOfLecture;
    if(counter[i].tutorialHours > course[i].hoursOfTutorial)
      violationCounter+= counter[i].tutorialHours - course[i].hoursOfTutorial;
    if(counter[i].practicalHours > course[i].hoursOfPractical)
      violationCounter+= counter[i].practicalHours - course[i].hoursOfPractical;
  }
  
  return violationCounter;
}

/**
 *  The purpose of this function is to check whether the number of 
 *  students in the class exceed the venue size or not
 *  
 *  return number of exceeded (the size of student in the class exceeded)
 *  return 0 (the size did not exceed)
 */
int determineViolationForCourseVenueSize(Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS]) {
  int VenueNumber = 0, day = 0, time = 0;
	int violationCounter = 0;

  for(VenueNumber = 0; VenueNumber < MAX_VENUE; VenueNumber++) {
    for(day = 0; day < MAX_DAY; day++) {
      for(time = 0; time < MAX_TIME_SLOTS; time++) {
				if(newClass[VenueNumber][day][time].course != NULL && newClass[VenueNumber][day][time].group != NULL){
          if(venue[VenueNumber].sizeOfVenue < newClass[VenueNumber][day][time].group->groupSize){
						violationCounter++;
					}
				}
      }
    }
  }
  return violationCounter;
}

/**
 *  This function is to check whether the same lecturer appear at 
 *  different venue or not
 *  
 *  return number of exceeded (got violation)
 *  return 0 (no violation)
 */
int checkIfLecturerAppearInTwoVenue(Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS], int day, int time){
	int venue, i;
	int counter[(sizeof(lecturer)/sizeof(Lecturer))] = { 0,0,0,0 };
	int returnCounter = 0;
	
	for(venue = 0 ; venue < MAX_VENUE ; venue++){
		for(i = 0; i < MAX_VENUE; i++){
			if(newClass[venue][day][time].lecturer){
				if(newClass[venue][day][time].lecturer == &lecturer[i])
					counter[i]++;
			}
		}
	}
  for(i = 0 ; i < (sizeof(lecturer)/sizeof(Lecturer)) ; i++){
		if(counter[i] > 1)
			returnCounter = counter[i] - 1;
	}
  return returnCounter;
}

/**
 *  This function is to check whether the same programme and same group 
 *  appears at different venue or not
 * 
 *  return value of exceeding (got violation)
 *  return 0 (no violation)
 */
int checkStudentViolation(Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS], int day, int time) {
  int venue, i;
	int counter[(sizeof(course)/sizeof(Course))] = { 0,0,0,0 };
	int returnCounter = 0;
  
  for(venue = 0; venue < MAX_VENUE; venue++) {
    for(i = 0; i < MAX_VENUE; i++) {
      if(newClass[venue][day][time].course){
				if(newClass[venue][day][time].course->programme == &programme[i])
					counter[i]++;
			}
    }
  }
  for(i = 0 ; i < (sizeof(course)/sizeof(Course)) ; i++){
		if(counter[i] > 1)
			returnCounter = counter[i] - 1;
	}
  return returnCounter;
}

//constraints function ends here

/**
 *  The purpose of this function is to check whether the chromosome
 *  have empty slots or not, if it has empty slots it will return the address 
 *  of the chromosome
 */
Class *checkChromosomeIsEmpty(Class newClass[4][MAX_DAY][MAX_TIME_SLOTS]) {
  int venue = 0;
  int day = 0, time = 0;
  
  for(venue; venue < MAX_VENUE; venue++) {
    for(day; day < MAX_DAY; day++) {
      for(time; time < MAX_TIME_SLOTS; time++) {
        if(newClass[venue][day][time].course == NULL && newClass[venue][day][time].lecturer == NULL)
          return &newClass[venue][day][time];
      }
    }
  }
}

void addDetailsIntoChromosome(Class newClass[4][MAX_DAY][MAX_TIME_SLOTS], Course course[], Lecturer lecturer[], Group group[], char typeOfClass){
	Class *addIntoClass = checkChromosomeIsEmpty(newClass);
	addIntoClass->lecturer = lecturer;
	addIntoClass->course = course;
	addIntoClass->typeOfClass = typeOfClass;
  addIntoClass->group = group;
}

int calculateFitnessScore(Class newClass[MAX_VENUE][MAX_DAY][MAX_TIME_SLOTS]){
	int venue = 0;
  int day = 0, time = 0;
	int violation = 0;
	
		
  for(venue = 0; venue < MAX_VENUE; venue++) {
    for(day = 0; day < MAX_DAY; day++) {
			if(venue == 0)
				violation += checkIfTutionOverloadedInSingleDay(newClass, day);
      for(time = 0; time < MAX_TIME_SLOTS; time++) {
				if(venue == 0){
					violation += checkIfLecturerAppearInTwoVenue(newClass, day, time);
					violation += checkStudentViolation(newClass, day, time);
				}
      }
    }
  }
  violation += determineViolationForCourseVenueSize(newClass);
    
	return violation;
}

void fillInTheChromosome(Class classList[]){

}