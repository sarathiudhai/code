Problem 1: LRU Cache Implementation
Logic and approach
I use two things to make both operations run in O(1) time.
- Unordered map: It helps me find a key quickly and know where it is in the list.
- Doubly linked list: It keeps the recently used item in the front and the least used item at the back. So, I can easily move or remove an item.
When I use get(key), if the key is there, I move it to the front and return its value. If the key is not there, I return -1.

When I use put(key, value), if the key is already there, I update its value and move it to the front. If the cache is full, I remove the least recently used item and add the new item to the front.



Problem 2: Event Scheduler
Logic and approach
We need to write two functions for this problem.

1. canAttend(events)

First, I sort all the events based on their start time. Then I check each event with the previous event. If the next event starts before the previous event ends, it means both events overlap, so I return false. Otherwise, I return true.

2. minRooms(events)

First, I sort the events by their start time. Then I use a min-heap to store the ending time of each meeting.

If a meeting ends before or at the start time of the next meeting, we can use the same room again. Otherwise, we need another room. I also keep track of the maximum number of rooms needed.

For example, if one meeting ends at 10 and another meeting starts at 10, both can use the same room because there is no overlap.


