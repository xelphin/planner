# Developer Notes

## Database Format
The data is saved in ```database.txt```. It is read by the program and a Calendar object is initialized.

## How database.txt looks like
```
2022

BANNERS

Reminder
["Remember Alice's Birthday on 11.18", "Edison Park", ""]
[11, 15, ""]
[11, 16, ""]
[11, 17, ""]

Task
["Buy gift for Alice", 2, "Buy daisies\n make accessorized headphones"]
[11, 17, 1400, false, ""]

Event
["Alice's Birthday", "Edison Park", "23 years old\nFairy themed"]
[11, 18, 1000, 1300, ""]

Task
["Finish Art Assignment", 0, ""]
[11, 17, true, ""]

```

### Understand database.txt

At the start we have the year the calendar is set to

#### Banner

Banner - Reminder
- [title, location, description]
Banner - Task
- [title, urgency, description]
Banner - Event
- [title, location, description]

#### Point

Point - Reminder
- [Banner ID, month, day, unique description]
Point - Task
- [Banner ID, month, day, deadline, completed, unique description]
Point - Event
- [Banner ID, month, day, timeStart, timeEnd unique description]




