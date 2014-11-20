#include "unity.h"
#include <stdio.h>
#include "TimeTabling.h"

void setUp(void){
  Group group[] = { {.groupName = "A2",
                     .groupSize = 10},
                     
                    {.groupName = "A3",
                     .groupSize = 13},
                     
                    {.groupName = "K2",
                     .groupSize = 20},
                     
                    {.groupName = "K3",
                     .groupSize = 19}
                  };
                 
  Venue venue[] = { {.nameOfVenue = "D203",
                     .sizeOfVenue = 40},
                     
                    {.nameOfVenue = "D300",
                     .sizeOfVenue = 25},
                     
                    {.nameOfVenue = "D204",
                     .sizeOfVenue = 30},
                     
                    {.nameOfVenue = "D301",
                     .sizeOfVenue = 25}
                  };
                  
  Lecturer lecturer[] = { {.lecturerName = "Poh TV",
                           .department = "FASC"},
                           
                          {.lecturerName = "Chan CK",
                           .department = "FASC"},
                          
                          {.lecturerName = "Chiu VT",
                           .department = "TR"},
                           
                          {.lecturerName = "Jackson Teh",
                           .department = "HSSchool"}
                        };
                        
  Programme programme[] = { {.programmeName = "RMB2",
                             &group[0]},
                            
                            {.programmeName = "RMB3",
                             &group[1]},
                             
                            {.programmeName = "RMM2",
                             &group[2]},
                             
                            {.programmeName = "RMM3",
                             &group[3]}
                          };
                      
  Course course[] = { {.courseCode = "AAMP2041",
                       .courseName = "Mathematics",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 2,
                       &programme[0],
                       .sizeOfProgramme = 20},
                       
                      {.courseCode = "AAMB2034",
                       .courseName = "English",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 0,
                       &programme[1],
                       .sizeOfProgramme = 30},
                       
                      {.courseCode = "ABMC1045",
                       .courseName = "History",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 0,
                       &programme[2],
                       .sizeOfProgramme = 15},
                      
                      {.courseCode = "ABCD1234",
                       .courseName = "Add Maths",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 0,
                       &programme[3],
                       .sizeOfProgramme = 30}
                    };
  
  
}

void tearDown(void){}

/**************************************************
 *  getCourseName() and getCourseCode() Functions *                                   
 **************************************************/
void test_getCourseName_should_able_to_get_wat(){

	Course newCourse[] = { {.courseCode = "MUET123",
                          .courseName = "English"}
                       };

	char *toCheckAnswer = getCourseName(newCourse[0]);
	
	TEST_ASSERT_EQUAL_STRING(newCourse[0].courseName, toCheckAnswer);

}

void test_getCourseName_should_able_to_get_lolno(){

	Course newCourse[] = { {.courseCode = "MUET123", 
                          .courseName = "Electronics"},
                         {.courseCode = "MATH456", 
                          .courseName = "TDD"}
                       };
	
  char *toCheckAnswer = getCourseName(newCourse[1]);
	TEST_ASSERT_EQUAL_STRING(newCourse[1].courseName, toCheckAnswer);

}

void test_getCourseCode_should_able_to_get_MUET123(){

	Course newCourse[] = {{.courseCode = "MUET123",
                         .courseName = "DLP"},
                        {.courseCode = "MATH123", 
                         .courseName = "Physics"}
                       };
	
  char *toCheckAnswer = getCourseCode(newCourse[0]);
	TEST_ASSERT_EQUAL_STRING(newCourse[0].courseCode, toCheckAnswer);

}

void test_getCourseCode_should_able_to_get_MATH(){

	Course newCourse[] = {{.courseCode = "MUET123", 
                         .courseName = "Moral"},
                        {.courseCode = "MATH321", 
                         .courseName = "Islamic Studies"}
                       };
	
  char *toCheckAnswer = getCourseCode(newCourse[1]);
	TEST_ASSERT_EQUAL_STRING(newCourse[1].courseCode, toCheckAnswer);
}

/***********************************************************************************
 *  getTotalStudentsInCourse() and getTotalStudentsInCourseofProgramme() functions *
 ***********************************************************************************/
void test_getTotalStudentsInCourse_given_the_groupSize_should_return_the_number_of_students(void) {
  int numberOfStudents;
  Group group = {.groupName = "RMB2",
                 .groupSize = 30
                };
               
  Class newClass = {.group = &group};
  
  numberOfStudents = getTotalStudentsInCourse(&newClass);
  TEST_ASSERT_EQUAL(group.groupSize, numberOfStudents);
}

void test_getVenueSize_given_the_size_of_venue_should_be_able_to_return_the_size_of_venue(void) {
  int venueSize;
  Venue venue = {.sizeOfVenue = 40};
  Class newClass = {.venue = &venue};
  
  venueSize = getVenueSize(&newClass);
  TEST_ASSERT_EQUAL(venue.sizeOfVenue, venueSize);
}
  
void test_addDetailsIntoChromosome_given_a_set_of_Class_details_should_be_able_to_add_things_into_the_chromosome(void) {
  Group group = {.groupName = "K2",
                 .groupSize = 40};
                 
  Programme programme = {.programmeName = "RMB2",
                          &group};
                        
  Course course = {.courseCode = "AAMP2042",
                   .courseName = "Test Driven Development",
                   .hoursOfLecture = 2,
                   .hoursOfTutorial = 1,
                   .hoursOfPractical = 2,
                   &programme,
                   .sizeOfProgramme = 40};
  
  Lecturer lecturer = {.lecturerName = "Poh TV",
                       .department = "FASC"};
                      
  Venue venue = {.nameOfVenue = "D203",
                 .sizeOfVenue = 40};
  
  Class chromosome[][5][8] = { {{&programme,
                            &course,
                            &lecturer,
                            &group,
                            &venue}}
                          };
                          
  addDetailsIntoChromosome(&chromosome);
  
 // printf("programme name: %s\n", chromosome[0][0][0].programme->programmeName);
}
