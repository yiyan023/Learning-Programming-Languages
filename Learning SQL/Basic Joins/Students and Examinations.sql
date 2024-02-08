# Write your MySQL query statement below
SELECT st.student_id, st.student_name, s.subject_name, COUNT(ex.subject_name) as attended_exams
FROM Students st CROSS JOIN Subjects s LEFT OUTER JOIN Examinations ex
ON st.student_id = ex.student_id and s.subject_name = ex.subject_name
GROUP BY st.student_id, s.subject_name
ORDER BY st.student_id, s.subject_name;