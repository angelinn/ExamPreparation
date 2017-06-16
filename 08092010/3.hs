type Trip = (String, Integer, Float)
type Tour = [Trip]

discount :: Tour -> Integer -> Tour
discount tour len = [ if k > len then (d, k, p / 10) else (d, k, p) | (d, k, p) <- tour ]

shortenTour :: Tour -> String -> String -> Trip -> Tour
shortenTour ((d, k, p) : rest) from to trip
    | d == from = extractTour rest to trip
    | otherwise = (d, k, p) : shortenTour rest from to trip

extractTour :: Tour -> String -> Trip -> Tour
extractTour ((d, k, p) : rest) to trip
    | d == to   = trip : rest
    | otherwise = extractTour rest to trip
