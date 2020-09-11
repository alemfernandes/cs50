SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
JOIN ratings ON stars.movie_id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;