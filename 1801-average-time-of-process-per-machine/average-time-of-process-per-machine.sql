# Write your MySQL query statement below
SELECT A1.machine_id, round(avg(A2.timestamp - A1.timestamp), 3) as processing_time
FROM Activity A1
JOIN Activity A2 
ON  A1.machine_id = A2.machine_id AND 
    A1.process_id = A2.process_id AND
    A1.activity_type = "start" 
    AND A2.activity_type = "end"
GROUP BY A1.machine_id;