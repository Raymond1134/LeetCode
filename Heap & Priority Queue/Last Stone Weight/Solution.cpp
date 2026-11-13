class Solution {
public:
    vector<int> stonesHeap;

    int lastStoneWeight(vector<int>& stones) {
        for (int stone : stones) {
            insertStone(stone);
        }

        while (stonesHeap.size() > 1) {
            int largestStone = popStone();
            int secondLargestStone = popStone();

            if (largestStone == secondLargestStone) continue;
            insertStone(largestStone - secondLargestStone);
        }
        
        return stonesHeap.empty() ? 0 : stonesHeap[0];
    }

    void insertStone(int stone) {
        int i = stonesHeap.size();
        stonesHeap.emplace_back(stone);

        int parent;
        while (i > 0) {
            parent = (i - 1) / 2;
            if (stonesHeap[parent] >= stonesHeap[i]) break;
            swap(stonesHeap[parent], stonesHeap[i]);
            i = parent;
        }
    }

    int popStone() {
        int largest = stonesHeap[0];
        stonesHeap[0] = stonesHeap.back();
        stonesHeap.pop_back();

        int n = stonesHeap.size();

        int i = 0;
        while (true) {
            int left = i*2 + 1;
            int right = left + 1;
            int largest = i;

            if (left < n && stonesHeap[left] > stonesHeap[largest]) largest = left;
            if (right < n && stonesHeap[right] > stonesHeap[largest]) largest = right;
            if (largest == i) break;

            swap(stonesHeap[largest], stonesHeap[i]);

            i = largest;
        }

        return largest;
    }
};