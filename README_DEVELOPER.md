# Developer Notes

## Database Format
The data is saved in ```database.txt```. It is read by the program and a Calendar object is initialized.

## How database.txt looks like
```
2022

Reminder
["Will Rain","","",-1, 11, 14]
[11,15]
[11,16]
-

Event
["Board Game Night","","Board games and wine night with Micheal and Lara",-1, 3, 2, 600, 1200]
[3, 9, 720, 1200]
[3, 12, 720, 1200]
-

Task
["Buy gift for Alice","","Buy daisies\n make accessorized headphones", 3, 11, 17, 1400, 1]
[11, 12, 300, 0]
-

Reminder
["Disco Party","Glass Hall","",-1, 11, 17]
-

Task
["Organize Bag","","Papers, food, notebooks...", 2, 10, 1, 1200, 0]
[10, 8, 1200, 0]
[10, 15, 1200, 0]
[10, 22, 1200, 0]
-

```

### Understand database.txt

At the start we have the year the calendar is set to

#### Banner (with a base Point)

Banner - Reminder
- [title, location, description, urgency, month, day]
Banner - Task
- [title, location, description, urgency, month, day, deadline, completed]
Banner - Event
- [title, location, description, urgency, month, day, timeStart, timeEnd]

#### Point

Point - Reminder
- [month, day]
Point - Task
- [month, day, deadline, completed]d
Point - Event
- [month, day, timeStart, timeEnd]

### RUN with checks

make
valgrind --leak-check=full ./Planner 

#### clean
make clean
