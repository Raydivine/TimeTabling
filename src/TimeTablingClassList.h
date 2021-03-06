#ifndef TimeTablingClassList_H
#define TimeTablingClassList_H
#include <stdio.h>
#include "ErrorCode.h"
#include "TimeTabling.h"

/******************************************************************************************************
 *  This file contains the List of every element in the TimeTabling, (List from Management)
 *	-	Group List
 *	-	Programme List
 *	-	Course List
 *	- Venue List
 *	-	Lecturer List
 *	- Class List
 *
 *	Group list			- The list of all groups from each particular Programmes
 *
 *	Programme list	- The list of programmes in a college/institute, each programme 
 *										contains 1 or more group(s)
 *
 *	Course list			-	The list of all courses, contains the programme(s) that taking the course
 *
 *	Venue list			- The list of all venues, contains size for each venue
 *
 *	Leturer list		- The list of lecturers, contains name and department
 *
 *	Class list			- The list of each class(combination of venue, course and lecturer in an hour slot).
 *										to fit into the Timetable.
 *******************************************************************************************************/

/***********************************************************************************
 *  Group list 
 ***********************************************************************************/
  Group group[] = { {.groupName = "A1",
                     .groupSize = 12},
                     
                    {.groupName = "A2",
                     .groupSize = 13},
                     
                    {.groupName = "B1",
                     .groupSize = 15},
                     
                    {.groupName = "B2",
                     .groupSize = 10},
                    
                    {.groupName = "C1",
                     .groupSize = 11},
                     
                    {.groupName = "C2",
                     .groupSize = 14},
                     
                    {.groupName = "D1",
                     .groupSize = 16},
                    
                    {.groupName = "D2",
                     .groupSize = 14},
                     
                    {.groupName = "E1",
                     .groupSize = 18},
                     
                    {.groupName = "E2",
                     .groupSize = 12},
                     
                    {.groupName = "F1",
                     .groupSize = 17},
                    
                    {.groupName = "F2",
                     .groupSize = 13},
                    
                    {.groupName = "G1",
                     .groupSize = 22},
                    
                    {.groupName = "G2",
                     .groupSize = 8}  
                  };
									
/***********************************************************************************
 *  Venue list 
 ***********************************************************************************/
                 
  Venue venue[] = { {.nameOfVenue = "D203",
                     .sizeOfVenue = 40,
										 .venueType = 'p'},
                     
                    {.nameOfVenue = "D300",
                     .sizeOfVenue = 25,
										 .venueType = 'a'},
                     
                    {.nameOfVenue = "D204",
                     .sizeOfVenue = 30,
										 .venueType = 'a'},
                     
                    {.nameOfVenue = "D301",
                     .sizeOfVenue = 60,
										 .venueType = 'a'}
                  };
                  
/***********************************************************************************
 *  Lecturer list 
 ***********************************************************************************/
  Lecturer lecturer[] = { {.lecturerName = "Poh TV",
                           .department = "FASC"},
                           
                          {.lecturerName = "Chan CK",
                           .department = "FASC"},
                          
                          {.lecturerName = "Chiu VT",
                           .department = "TR"},
                           
                          {.lecturerName = "Jackson TKS",
                           .department = "HSSchool"},
                          
                          {.lecturerName = "Cheah SL",
                           .department = "FABS"},
                          
                          {.lecturerName = "Wong YY",
                           .department = "FBUS"},
                          
                          {.lecturerName = "Wong KH",
                           .department = "Char Kuey Teow"},
                           
                          {.lecturerName = "VT Chiu",
                           .department = "Gay School"},
                           
                          {.lecturerName = "Low TH",
                           .department = "SH"},
                           
                          {.lecturerName = "Lai JY",
                           .department = "FHGU"}
                        };
                        
/***********************************************************************************
 *  Program list 
 ***********************************************************************************/
  Programme programme[] = { {.programmeName = "RMB2",
                             .group[0] = &group[0],
                             .group[1] = &group[1],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMB3",
                             .group[0] = &group[2],
                             .group[1] = &group[3],
                             .group[2] = NULL},
                             
                            {.programmeName = "RMM2",
                             .group[0] = &group[4],
                             .group[1] = &group[5],
                             .group[2] = NULL},
                             
                            {.programmeName = "RMM3",
                             .group[0] = &group[6],
                             .group[1] = &group[7],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMS2",
                             .group[0] = &group[8],
                             .group[1] = &group[9],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMS3",
                             .group[0] = &group[10],
                             .group[1] = &group[11],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMT2",
                             .group[0] = &group[12],
                             .group[1] = &group[13],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMT3",
                             .group[0] = &group[14],
                             .group[1] = &group [15],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMA2",
                             .group[0] = &group[16],
                             .group[1] = &group[17],
                             .group[2] = NULL},
                            
                            {.programmeName = "RMA3",
                             .group[0] = &group[18],
                             .group[1] = &group[19],
                             .group[2] = NULL}
                          };
                      
/***********************************************************************************
 *  Course list 
 ***********************************************************************************/
  Course course[] = { {.courseCode = "AAMP2041",
                       .courseName = "Mathematics",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 2,
                       .programme[0] = &programme[0],
                       .programme[1] = &programme[1],
                       .programme[2] = NULL,
                       .sizeOfProgramme = 20},
                       
                      {.courseCode = "AAMB2034",
                       .courseName = "English",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 0,
                       .programme[0] = &programme[1],
                       .programme[1] = &programme[2],
                       .programme[2] = NULL,
                       .sizeOfProgramme = 30},
                       
                      {.courseCode = "ABMC1045",
                       .courseName = "History",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 0,
                       .programme[0] = &programme[2],
                       .programme[1] = &programme[3],
											 .programme[2] = NULL,
                       .sizeOfProgramme = 15},
                      
                      {.courseCode = "ABCD1234",
                       .courseName = "Add Maths",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 0,
                       .programme[0] = &programme[3],
                       .programme[1] = &programme[4],
											 .programme[2] = NULL,
                       .sizeOfProgramme = 30},
                       
                      {.courseCode = "AAMP1034",
                       .courseName = "Test Driven Development",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 2,
                       .hoursOfPractical = 2,
                       .programme[0] = &programme[4],
                       .programme[1] = &programme[5],
											 .programme[2] = NULL,
                       .sizeOfProgramme = 10},
                       
                      {.courseCode = "EFGH5656",
                       .courseName = "Electromagnetics",
                       .hoursOfLecture = 2,
                       .hoursOfTutorial = 1,
                       .hoursOfPractical = 2,
                       .programme[0] = &programme[5],
                       .programme[1] = &programme[6],
											 .programme[2] = NULL,
                       .sizeOfProgramme = 20}
                    };
										
/***********************************************************************************
 *  Class list 
 *	- The total class for each course, programme and group
 ***********************************************************************************/
Class classList[52] = {{.course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 'l',
												.group[0] = &group[0],
												.group[1] = &group[1],
												.group[2] = &group[2],
												.group[3] = &group[3],
												.group[4] = NULL
											},
											{	.course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 'l',
												.group[0] = &group[0],
												.group[1] = &group[1],
												.group[2] = &group[2],
												.group[3] = &group[3],
												.group[4] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 't',
												.group[0] = &group[0],
												.group[1] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 't',
												.group[0] = &group[1],
												.group[1] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 't',
												.group[0] = &group[2],
												.group[1] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 't',
												.group[0] = &group[3],
												.group[1] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 'p',
												.group[0] = &group[0],
												.group[1] = &group[1],
												.group[2] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 'p',
												.group[0] = &group[0],
												.group[1] = &group[1],
												.group[2] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 'p',
												.group[0] = &group[2],
												.group[1] = &group[3],
												.group[2] = NULL
											},
											{ .course = &course[0],
												.lecturer = &lecturer[4],
												.typeOfClass = 'p',
												.group[0] = &group[2],
												.group[1] = &group[3],
												.group[2] = NULL
											},
											
											{ .course = &course[1],
												.lecturer = &lecturer[3],
												.typeOfClass = 'l',
												.group[0] = &group[2],
												.group[1] = &group[3],
												.group[2] = &group[4],
												.group[3] = &group[5],
												.group[4] = NULL
											},
											{ .course = &course[1],
												.lecturer = &lecturer[3],
												.typeOfClass = 'l',
												.group[0] = &group[2],
												.group[1] = &group[3],
												.group[2] = &group[4],
												.group[3] = &group[5],
												.group[4] = NULL
											},
											{ .course = &course[1],
												.lecturer = &lecturer[3],
												.typeOfClass = 't',
												.group[0] = &group[2],
												.group[1] = NULL
											},
											{ .course = &course[1],
												.lecturer = &lecturer[3],
												.typeOfClass = 't',
												.group[0] = &group[3],
												.group[1] = NULL
											},
											{ .course = &course[1],
												.lecturer = &lecturer[3],
												.typeOfClass = 't',
												.group[0] = &group[4],
												.group[1] = NULL
											},
											{ .course = &course[1],
												.lecturer = &lecturer[3],
												.typeOfClass = 't',
												.group[0] = &group[5],
												.group[1] = NULL
											},

											{ .course = &course[2],
												.lecturer = &lecturer[2],
												.typeOfClass = 'l',
												.group[0] = &group[4],
												.group[1] = &group[5],
												.group[2] = &group[6],
												.group[3] = &group[7],
												.group[4] = NULL
											},
											{ .course = &course[2],
												.lecturer = &lecturer[2],
												.typeOfClass = 'l',
												.group[0] = &group[4],
												.group[1] = &group[5],
												.group[2] = &group[6],
												.group[3] = &group[7],
												.group[4] = NULL
											},
											{ .course = &course[2],
												.lecturer = &lecturer[2],
												.typeOfClass = 't',
												.group[0] = &group[4],
												.group[1] = NULL
											},
											{ .course = &course[2],
												.lecturer = &lecturer[2],
												.typeOfClass = 't',
												.group[0] = &group[5],
												.group[1] = NULL
											},
											{ .course = &course[2],
												.lecturer = &lecturer[2],
												.typeOfClass = 't',
												.group[0] = &group[6],
												.group[1] = NULL
											},
											{ .course = &course[2],
												.lecturer = &lecturer[2],
												.typeOfClass = 't',
												.group[0] = &group[7],
												.group[1] = NULL
											},
											
											{ .course = &course[3],
												.lecturer = &lecturer[5],
												.typeOfClass = 'l',
												.group[0] = &group[6],
												.group[1] = &group[7],
												.group[2] = &group[8],
												.group[3] = &group[9],
												.group[4] = NULL
											},
											{ .course = &course[3],
												.lecturer = &lecturer[5],
												.typeOfClass = 'l',
												.group[0] = &group[6],
												.group[1] = &group[7],
												.group[2] = &group[8],
												.group[3] = &group[9],
												.group[4] = NULL
											},
											{ .course = &course[3],
												.lecturer = &lecturer[5],
												.typeOfClass = 't',
												.group[0] = &group[6],
												.group[1] = NULL
											},
											{ .course = &course[3],
												.lecturer = &lecturer[5],
												.typeOfClass = 't',
												.group[0] = &group[7],
												.group[1] = NULL
											},
											{ .course = &course[3],
												.lecturer = &lecturer[5],
												.typeOfClass = 't',
												.group[0] = &group[8],
												.group[1] = NULL
											},
											{ .course = &course[3],
												.lecturer = &lecturer[5],
												.typeOfClass = 't',
												.group[0] = &group[9],
												.group[1] = NULL
											},
											
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 'l',
												.group[0] = &group[8],
												.group[1] = &group[9],
												.group[2] = &group[10],
												.group[3] = &group[11],
												.group[4] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 'l',
												.group[0] = &group[8],
												.group[1] = &group[9],
												.group[2] = &group[10],
												.group[3] = &group[11],
												.group[4] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[8],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[8],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[9],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[9],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[10],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[10],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[11],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 't',
												.group[0] = &group[11],
												.group[1] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 'p',
												.group[0] = &group[8],
												.group[1] = &group[9],
												.group[2] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 'p',
												.group[0] = &group[8],
												.group[1] = &group[9],
												.group[2] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 'p',
												.group[0] = &group[10],
												.group[1] = &group[11],
												.group[2] = NULL
											},
											{ .course = &course[4],
												.lecturer = &lecturer[0],
												.typeOfClass = 'p',
												.group[0] = &group[10],
												.group[1] = &group[11],
												.group[2] = NULL
											},
											
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 'l',
												.group[0] = &group[10],
												.group[1] = &group[11],
												.group[2] = &group[12],
												.group[3] = &group[13],
												.group[4] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 'l',
												.group[0] = &group[10],
												.group[1] = &group[11],
												.group[2] = &group[12],
												.group[3] = &group[13],
												.group[4] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 't',
												.group[0] = &group[10],
												.group[1] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 't',
												.group[0] = &group[11],
												.group[1] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 't',
												.group[0] = &group[12],
												.group[1] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 't',
												.group[0] = &group[13],
												.group[1] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 'p',
												.group[0] = &group[10],
												.group[1] = &group[11],
												.group[2] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 'p',
												.group[0] = &group[10],
												.group[1] = &group[11],
												.group[2] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 'p',
												.group[0] = &group[12],
												.group[1] = &group[13],
												.group[2] = NULL
											},
											{ .course = &course[5],
												.lecturer = &lecturer[1],
												.typeOfClass = 'p',
												.group[0] = &group[12],
												.group[1] = &group[13],
												.group[2] = NULL
											}
											};
#endif // TimeTablingClassList_H
