# Developer Notes

## Database Format
The data is saved in ```database.txt```. It is read by the program and a Calendar object is initialized.

## How database.txt looks like
```
2022

[0, "Remember Alice's Birthday on 11.18", "Edison Park", ""]
[11, 15, ""]
[11, 16, ""]
[11, 17, ""]

[1, "Buy gift for Alice", 2, "Buy daisies\n make accessorized headphones"]
[11, 17, 1400, false, ""]

[2, "Alice's Birthday", "Edison Park", "23 years old\nFairy themed"]
[11, 18, 1000, 1300, ""]

[1, "Finish Art Assignment", 0, ""]
[11, 17, true, ""]

```

### Understand database.txt

At the start we have the year the calendar is set to

#### Banner

Banner - Reminder
- [type, title, location, description]
Banner - Task
- [type, title, urgency, description]
Banner - Event
- [type, title, location, description]

TYPE:
- 0: Reminder
- 1: Task
- 2: Event

#### Point

Point - Reminder
- [month, day, unique description]
Point - Task
- [month, day, deadline, completed, unique description]
Point - Event
- [month, day, timeStart, timeEnd unique description]




