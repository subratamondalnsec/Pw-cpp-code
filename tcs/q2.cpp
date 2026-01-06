Input
Line 1: N - This integer represents the total number of log entries recorded by the system.
Lines 2 to N+1: Log Entries - Each line describes a single employee activity and follows this structure:
EmployeeID: An integer representing the unique ID of the employee.
Activity: A string indicating either "enters" or "exits".
Location: A string specifying where the activity occurred (e.g., "room1", "cafeteria2", "pantry3").
Time: A string representing the time of the activity in 12-hour format (e.g., "10:30 AM").
Line N+2: Suspect EmployeeID - This line contains a single integer, the ID of the employee the manager is suspicious about.
Output
Single line consisting of 'Yes/No/Cannot be determined'.

Yes - if the manager's suspicion is correct

No - if the manager's suspicion is incorrect

Cannot be determined - if it is not possible to determine whether the suspected employee had worked for the least duration or not.

Time Limit (secs)
1

Examples
Example 1

Input

10

101 enters cafeteria1 9:01AM

101 exits cafeteria1 10:17AM

154 enters room5 9:15AM

153 exits room4 11:40AM

153 enters pantry2 2:00PM

101 enters room4 12:01PM

154 exits room5 1:05PM

153 exits pantry2 4:00PM

153 enters room4 10:16AM

101 exits room4 1:25PM

153

Output

Yes