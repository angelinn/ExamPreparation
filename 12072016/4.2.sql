aSELECT studioname, starname, COUNT(starname)
FROM movie JOIN starsin ON title = movietitle AND year = movieyear
WHERE studioname IS NOT NULL
GROUP BY studioname, starname
HAVING COUNT(SELECT starname FROM movie, starsin 
             WHERE title = movietitle AND year = movieyear) >= MAX(starname)

SELECT studioname, starname, COUNT(starname)
FROM movie m LEFT JOIN starsin ON title = movietitle AND year = movieyear
WHERE studioname IS NOT NULL
GROUP BY studioname, starname
HAVING COUNT(SELECT starname FROM movie, starsin
             WHERE title = movietitle AND year = movieyear) >= 
                                        ALL (SELECT COUNT(*) FROM MOVIE, starsin
                                             WHERE title = movietitle AND year = movieyear
                                             GROUP BY studioname, starname)

SELECT studioname, starname, COUNT(DISTINCT starname)
FROM movie m JOIN starsin ON title = movietitle and year = movieyear
WHERE studioname IS NOT NULL
GROUP BY m.studioname, starname
HAVING COUNT(starname) >= ALL (SELECT COUNT(DISTINCT starname)
                                FROM movie, starsin WHERE title = movietitle AND year = movieyear
                                AND studioname = m.studioname
                                GROUP BY studioname, starname)

-- ще изкара няколко записа за един и същи актьор в различно студио при вложената заявка
SELECT studioname, starname, COUNT(*)
FROM movie m JOIN starsin ON title = movietitle and year = movieyear
WHERE studioname IS NOT NULL
GROUP BY m.studioname, starname
HAVING COUNT(*) >= ALL (SELECT COUNT(*)
                                FROM movie, starsin WHERE title = movietitle AND year = movieyear
                                AND studioname = m.studioname
                                GROUP BY studioname, starname)
                                                               