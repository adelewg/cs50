SELECT name FROM people
WHERE id IN (SELECT person_id from stars
WHERE movie_id IN (SELECT movie_id FROM stars
WHERE person_id = (SELECT id FROM people WHERE name = "Kevin Bacon" and birth ="1958")))
and NOT name = "Kevin Bacon";
