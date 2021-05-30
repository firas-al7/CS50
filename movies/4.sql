--SELECT DISTINCT rating FROM ratings ORDER BY rating DESC;
--SELECT count(title) FROM movies WHERE (SELECT movie_id FROM ratings WHERE ratings.rating = 10) = movies.id;
SELECT COUNT(*) FROM ratings WHERE rating = 10.0;