totalMin :: [(Int -> Int)] -> (Int -> Int)
totalMin (x:xs) = (totalMinRec xs (x 0) x)

totalMinRec :: [(Int -> Int)] -> Int -> (Int -> Int) -> (Int -> Int)
totalMinRec [] _ foo = foo
totalMinRec (x:xs) min foo
    | min < x 0 = totalMinRec xs min foo
    | otherwise = totalMinRec xs (x 0) x
