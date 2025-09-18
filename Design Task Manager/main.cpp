class TaskManager {
    private:
        unordered_map<int, pair<int, int>> tasktoUser;
        set<vector<int>> tasks;

    public:
        TaskManager(vector<vector<int>>& t) {
            for(vector<int>& task : t) {
                tasktoUser[task[1]] = {task[0], task[2]};
                tasks.insert({task[2], task[1], task[0]});
            }
        }

        void add(int userId, int taskId, int priority) {
            tasktoUser[taskId] = {userId, priority};
            tasks.insert({priority, taskId, userId});
        }

        void edit(int taskId, int newPriority) {
            int userId = tasktoUser[taskId].first;
            int priority = tasktoUser[taskId].second;

            tasks.erase({priority, taskId, userId});

            tasks.insert({newPriority, taskId, userId});
            tasktoUser[taskId] = {userId, newPriority};
        }

        void rmv(int taskId) {
            int userId = tasktoUser[taskId].first;
            int priority = tasktoUser[taskId].second;

            tasks.erase({priority, taskId, userId});
            tasktoUser.erase(taskId);
        }

        int execTop() {
            if(tasks.empty()) return -1;

            vector<int> top = *tasks.rbegin();

            tasks.erase(top);

            return top[2];
        }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */