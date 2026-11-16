class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        # Make a variable to store the result
        result = []

        # We are going to be doing a linear sweep, so we make a variable i
        # to keep track of where we currently are in intervals
        i = 0

        # Just to make the code easier to read, we make a helper variable
        # that stores the number of intervals prior to adding the new one
        numberOfIntervals = len(intervals)


        # First, copy over any intervals that end before newInterval.
        # For example, if we have:
        #   Intervals = [[1, 3], [4, 5], [9, 12], [13, 15]]
        #   newInterval = [6, 7],
        # then we simply copy over all intervals that END on a number SMALLER than 6

        # To do this, we loop through every interval in intervals.
        # Below, you see 'for interval in intervals:'. This is python syntax for a loop that runs once
        # for each element in intervals, starting with the first and ending with the last. In each
        # iteration of the loop, we can use the local variable 'interval' to access the current element. 
        for interval in intervals:

            # We only care about intervals BEFORE newInterval. So we break out of the loop when we reach
            # an element that is too big. For example, if we have:
            #   Intervals = [[1, 3], [4, 5], [9, 12], [13, 15]]
            #   newInterval = [6, 7],
            # then we should not include [9, 12] for now.
            if (interval[1] >= newInterval[0]):
                break

            # Append is python syntax for 'add this to the end of my list'.
            result.append(interval)

            # Keep track of where we are in the list for later
            i += 1
        
        # As an example of what has happened so far, we will do a trace.
        # Suppose we had:
        #   Intervals = [[1, 3], [4, 5], [9, 12], [13, 15]]
        #   newInterval = [6, 7],
        # then after the first iteration of the loop, result = [[1, 3]] and i = 1.
        # After the second iteration, result = [[1, 3], [4, 5]] and i = 2.
        # In the third iteration of the loop, 'interval' = [9, 12], so interval[1] = 12.
        # Notice that interval[1] >= newInterval[0] since 12 >= 7, so we don't add this interval yet.
        # We break out of the loop and never get to increment i, so we end up with:
        #   result = [[1, 3], [4, 5]]
        #   i = 2


        # Now we will merge all overlapping intervals into newInterval.
        # Observe that an interval overlaps with newInterval if its start is <= newInterval's end.
        # For example, if newInterval is [6, 9], then [8, 10] overlaps since 8 is less than 9.

        # So the below while condition is basically:
        #   'While the intervals are still overlapping with newInterval'.
        while i < numberOfIntervals and intervals[i][0] <= newInterval[1]:

            # To merge two intervals that overlap, simply take the smaller lower bound
            # and the larger upper bound. For example, to merge [6, 9] and [8, 10], we take
            # the smaller of 6 and 8 and the larger of 9 and 10 to get [6, 10].
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1

        result.append(newInterval)
        

        # Finally, all that's left is to add everything that comes AFTER newInterval.
        while i < numberOfIntervals:
            result.append(intervals[i])
            i += 1
            
        return result