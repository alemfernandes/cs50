SELECT avg(rating) AS "Average Rating 2012" FROM ratings
JOIN movies ON id = movie_id WHERE year = 2012;