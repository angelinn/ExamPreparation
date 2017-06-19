filterByChar :: Char -> [String] -> [String]
filterByChar c ls = filter (\x -> elem c x) ls

-- Създава се временен tuple (x, y, z)'
-- Масивът от char-ове "Curry" се присвоява на (x:y) => ('C', "urry", [])
let (x:y):z = ["Curry"] in (x, y, z)