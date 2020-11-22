--Functions by Ashley Zhao 10193698--
--Haskell--

charCat :: [Char] -> Int 
charCat letter
  | letter == "a" = 1
  | letter == "b" = 1
  | letter == "c" = 1
  | letter == "d" = 1
  | letter == "e" = 1
  | letter == "f" = 1
  | letter == "g" = 1
  | letter == "h" = 1
  | letter == "i" = 1
  | letter == "j" = 1
  | letter == "k" = 1
  | letter == "l" = 1
  | letter == "m" = 1
  | letter == "n" = 1
  | letter == "o" = 1
  | letter == "p" = 1
  | letter == "q" = 1
  | letter == "r" = 1
  | letter == "s" = 1
  | letter == "t" = 1
  | letter == "u" = 1
  | letter == "v" = 1
  | letter == "w" = 1
  | letter == "x" = 1
  | letter == "y" = 1
  | letter == "z" = 1
  | letter == "A" = 2
  | letter == "B" = 2
  | letter == "C" = 2
  | letter == "D" = 2
  | letter == "E" = 2
  | letter == "F" = 2
  | letter == "G" = 2
  | letter == "H" = 2
  | letter == "I" = 2
  | letter == "J" = 2
  | letter == "K" = 2
  | letter == "L" = 2
  | letter == "M" = 2
  | letter == "N" = 2
  | letter == "O" = 2
  | letter == "P" = 2
  | letter == "Q" = 2
  | letter == "R" = 2
  | letter == "S" = 2
  | letter == "T" = 2
  | letter == "U" = 2
  | letter == "V" = 2
  | letter == "W" = 2
  | letter == "X" = 2
  | letter == "Y" = 2
  | letter == "Z" = 2
  | letter == "0" = 3
  | letter == "1" = 3
  | letter == "2" = 3
  | letter == "3" = 3
  | letter == "4" = 3
  | letter == "5" = 3
  | letter == "6" = 3
  | letter == "7" = 3
  | letter == "8" = 3
  | letter == "9" = 3
  | otherwise = 4
  
coneVolume :: Float -> Float -> Float
coneVolume radius height = 
  (pi * radius * height) / 3
  where
    pi = 3.14159265359

oddDigits :: Integer -> Bool
oddDigits 0 = error "Please enter a number greater than 0"
oddDigits n 
  | n < 0 = error "Please enter a number greater than 0"
  | mod n 10 == n = True
  | mod n 100 == n = False 
  | otherwise = oddDigits (div n 100)
  
rpm :: Integer -> Integer -> Integer
rpm a b
  | mod b 2 == 0 =(a * 2) * (div b 2)
  | otherwise = (a * 2) * (div b 2) + a 