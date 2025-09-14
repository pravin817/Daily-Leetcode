SELECT user.name as name, SUM(if (ride.distance is NULL, 0, ride.distance)) as travelled_distance
FROM Users user
LEFT JOIN Rides ride
ON user.id = ride.user_id
GROUP BY user.id
ORDER BY travelled_distance DESC, name ASC;
