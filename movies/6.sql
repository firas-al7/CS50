--SELECT AVG(rating) FROM ratings WHERE (SELECT year FROM movies) = 2012;
SELECT AVG(rating) FROM ratings JOIN movies ON movies.id = ratings.movie_id WHERE movies.year = 2012;