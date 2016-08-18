# AJsAssignmentProblem
Method to solving Assignment Optimization Problem, alternate to Hungarian Method


#Update July 27th
This is the initial upload. Just wanted to get things started. Will be working on both Word and CPP files daily. Extremely RAW work so far.

#Update July 27th Pt. 2
Cleaned up the code a little. At least it looks organized. Still a long way to go.

#Update July 28th, 11:55AM
Added satMatrix function and random matrix generator. Need to fix satMatrix for loop that goes through columns and make it declare the earliest, smallest entry as the minimum for that row.

#Update July 29th, 9:25AM
I added a solution checker for any user-inputed 5x5 assignment matrix. Brute force method, summing elements from one row each and making sure those elements don't occupy the same column.

#August 1st, 4:08PM
No code update today. Didn't work on it over the weekend but gave some thought on how I wanted to attain (row, column) coordinates for the minima in the assignment matrix. I have a method, just working on making it nice and readable.

#August 8th, 12:43PM
I have been working on code (no word/ppt update yet) consistently. I'll have the new cpp up later on today. Currently trying to acquire minimum values in the "new table" and then make the changes in the assignMatrix based off those minimum values.

#August 9th, 2:11PM
Created new folder so I can post all .cpp files as I progress. New .cpp file.

#August 18th, 10:25AM
Uploaded pdf file containing walkthrough of my method so you can do the problem by hand. Also updated the AssignmentChecker; it spits out the coordinates of the optimal assignments. The output is a little ugly for now. Will mop it up soon and update.
