merge :: [Int] -> [Int] -> [Int]
merge x [] = x
merge [] y = y
merge (x:xs) (y:ys) = if x < y
                        then x : merge xs (y:ys)
                        else y : merge (x:xs) ys

(\list -> [y | y <- list, even y]) [1, 2, 3, 4]