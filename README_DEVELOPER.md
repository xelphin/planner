# Developer Notes

## Database Format
The data is saved in ```database.txt```. It is read by the program and a Calendar object is initialized.

## How database.txt looks like
```
2022

Reminder
["Remember Alice's Birthday on 11.18", 11, 11, true, [11,16], ""]

Task
["Buy gift for Alice", 11, 17, false, [], -1, 2, "Buy daisies\n make accessorized headphones"]

Event
["Alice's Birthday", 11, 18, false, [], 1050, 1260, "Edison Park", "23 years old\nFairy themed"]
```

### Understand database.txt
At the start we have the year the calendar is set to

- Reminder: [title, month, day, repeat, \[\[month,day]], description]
> The repeat array is 1D, but I wrote in 2D format (^ here and below) for it to be clearer
- Task: [title, month, day, repeat, \[\[month,day,deadline]], deadline, urgency, description]
> Urgency: 1 - most, 5 - least, 0 - empty
- Event: [title, month, day, repeat, \[\[month,day,timeStart, timeEnd]], timeStart, timeEnd, location, description]
> -1: All day (can be applied in timeStart/timeEnd/deadline)



