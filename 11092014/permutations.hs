perm :: [a] => [[a]]
perm [] = []
perm (x:[]) = [[x]]
perm (h:t) = foldr1 (++) [ insert h pt | pt <- perm t ]

insert :: a -> [a] -> [[a]]
insert h l = [ insertAt h [] l i | i <- [0..(length l)] ]

insertAt :: a -> [a] -> [a] -> Int -> [a]
insertAt h x y 0 = (x ++ [h]) ++ y
insertAt h x (yh:yt) i = insertAt h (x ++ [yh]) yt (i - 1)
