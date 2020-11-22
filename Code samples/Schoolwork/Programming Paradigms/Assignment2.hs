--Ashley Zhao--
--10193698--

module Assignment2 where

type Project = (String, String, Int)
type CourseData = [Project]

--Problem 1: Finding sublists with a specified sum

--Gets all the sublists and returns those whose sum is equal to the target value.
--Calls on: findSublists, sumOfList
sublistSum (x:xs) num = [x | x <- findSublists (x:xs), sumOfList x 0 == num, x /= []]

--Returns an integer value of the sum of numbers in a list parameter.
sumOfList [] count = count
sumOfList (x:xs) count = sumOfList xs (count+x)

--Finds all the sublists of a list.  Returns a list of lists.
findSublists [] = [[]]
findSublists (a:bs) = [a : part | part <- findSublists bs] ++ findSublists bs


--Problem 2: Matching Elements in a Pair of Lists

--Gets the two lists
--Calls on: matchingHelper
matching list1 list2 = matchingHelper list1 list2 0

--Returns the index of the list (as an accumulator)
matchingHelper [] (y:ys) index = []
matchingHelper (x:xs) [] index = []
matchingHelper (x:xs) (y:ys) index 
    | x == y = index : matchingHelper xs ys (index+1)
    | otherwise = matchingHelper xs ys (index+1)


--------------------------------Le Project----------------------------------------------------------------

--legalCourse checks for duplicate names and duplicate teams
--Calls on: checkDup
legalCourse [] = True
legalCourse ((name1, name2, _):xs)
    | name1 == name2 = False
	| name1 /= name2 = checkDup (name1, name2) xs
	| otherwise = legalCourse xs

--Checks if the same team shows up 
checkDup (name1, name2) [] = True
checkDup (name1, name2) ((namea, nameb, _):xs)
    | name1 == namea && name2 == nameb = False
    | name1 == nameb && name2 == namea = False
    | otherwise = checkDup (name1, name2) xs	
	
--studentCount checks for number of projects students worked on
--Calls on: takeCount
studentCount name project = takeCount name project 0

--Checks for number of projects student worked on
takeCount name [] counter = counter
takeCount name ((name1, name2, _):xs) counter
    | name == name1 || name == name2 = takeCount name xs (counter+1)
	| otherwise = takeCount name xs (counter)
	
--Partner returns a list of all the students target student worked with
partners name [] = []
partners name ((name1, name2, _):xs)
    | name == name1 = name2 : partners name xs
	| name == name2 = name1 : partners name xs
	| otherwise = partners name xs

--courseAvg calculates the average of all the marks
--Calls on: addMarks
courseAvg [] = 0
courseAvg project = fromIntegral (addMarks project) / fromIntegral (length project)

--Receives a Project list and adds up its marks
addMarks [] = 0
addMarks ((_,_,mark):xs) = mark + addMarks xs

--studentAvg calculates a student's average.
--Calls on: addMarksStudent, countProjects
studentAvg name [] = 0
studentAvg name project
    | countProjects name project 0 == 0 = 0
	| otherwise = fromIntegral (addMarksStudent name project) / fromIntegral (countProjects name project 0)

--Returns the total marks student has gotten on their project
addMarksStudent name [] = 0
addMarksStudent name ((name1,name2,mark):xs)
    | name1 ==  name || name2 == name = mark + addMarksStudent name xs 
	| otherwise = addMarksStudent name xs 

--Returns the total counter of projects a student has worked on
countProjects name [] counter = counter
countProjects name ((name1,name2,mark):xs) counter 
    | name1 ==  name || name2 == name = countProjects name xs (counter+1)
	| otherwise = countProjects name xs (counter)
	
--students first creates a list of all the student names (with duplicates) and removes the duplicate elements,
--returning the modified list.
--Calls on: removeDup
students [] = []
students ((name1, name2, _):xs) = removeDup ((name1 : students xs) ++ (name2 : students xs))

--removeDup checks if an element exists in a list.  If there is no duplicate, it appends the element to 
--the new list.
--Calls on: checkExist
removeDup [] = []
removeDup (x:xs)
    | checkExist x xs == False = x : removeDup xs
	| otherwise = removeDup xs

--checkExist checks if an element already exists in a list.
checkExist x [] = False
checkExist x (y:ys)
    | x == y = True
	| otherwise = checkExist x ys