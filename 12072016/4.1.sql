SELECT t.name, title
FROM Movie m JOIN (SELECT name, cert#
                    FROM movieexec
                    WHERE cert# IN (SELECT producerc# FROM Movie WHERE title = 'Pretty Woman')) t
ON m.producerc# = t.cert#

-- Селектва name и title от заявка, връщаща само cert
SELECT name, title
FROM (SELECT cert# FROM movieexec INTERSECT SELECT producerc# FROM movie WHERE title = 'Pretty Woman') t

-- Ще изведе само Pretty Woman
SELECT name, title
FROM Movie m
INNER JOIN movieexec me on m.producerc# = me.cert#
WHERE title = 'Pretty Woman'

-- Показва всичко освен Pretty Woman
SELECT name, title
FROM movie m LEFT JOIN movieexec me on m.producerc# = me.cert#
WHERE me.cert# NOT IN (SELECT producerc#
                        FROM movie
                        WHERE title = 'Pretty Woman')