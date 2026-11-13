class KthLargest {
public:
    int k;
    vector<int> nums;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        push(val);

        if (nums.size() > k) {
            pop();
        }

        return nums[0];
    }

private:
    void push(int val) {
        nums.push_back(val);
        sift_up(nums.size() - 1);
    }

    void pop() {
        nums[0] = nums.back();
        nums.pop_back();
        sift_down(0);
    }

    void sift_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (nums[parent] <= nums[i]) break;

            swap(nums[parent], nums[i]);
            i = parent;
        }
    }

    void sift_down(int i) {
        int n = nums.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && nums[left] < nums[smallest])
                smallest = left;

            if (right < n && nums[right] < nums[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(nums[i], nums[smallest]);
            i = smallest;
        }
    }
};