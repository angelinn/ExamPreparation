totalMin :: [Int -> Int] -> (Int -> Int)
totalMin (x:xs) = (totalMinRec xs (x 0) x)

totalMinRec :: [Int -> Int] -> Int -> (Int -> Int) -> (Int -> Int)
totalMinRec [] _ foo = foo
totalMinRec (x:xs) min foo
    | min < x 0 = totalMinRec xs min foo
    | otherwise = totalMinRec xs (x 0) x

chainMinCompositions :: (Int -> Int) -> [Int -> Int]
chainMinCompositions f = chainMinRec f [] 

chainMinRec :: (Int -> Int) -> [Int -> Int] -> [Int -> Int]
chainMinRec f foos
    | len == 0                                    = chainMinRec id (foos ++ [id])
    | len == 1                                    = f : chainMinRec f (foos ++ [f])
    | or [ preprev i /= prev i  | i <- [1..len] ] = let foo = (prev . preprev)
                                                    in f : chainMinRec foo (foos ++ [foo])
    | and [ preprev i == prev i | i <- [1..len] ] = let foo = totalMin foos
                                                    in f : chainMinRec foo (foos ++ [foo])
    where 
        preprev = last (init foos)
        prev    = last foos
        len     = length foos
