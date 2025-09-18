class TaskManager {
public:
    unordered_map<int,pair<int,int>>taskList; 
    //taskId -> {priority, userId}
    priority_queue<pair<int,int>>pq; 
    //{priority, taskId}
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &vec : tasks){
            int userId = vec[0];
            int taskId = vec[1];
            int priority = vec[2];
            taskList[taskId] = {priority, userId};
            pq.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskList[taskId]={priority, userId};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int currP = taskList[taskId].first;
        int currU = taskList[taskId].second;
        taskList[taskId] = {newPriority, currU};
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskList.erase(taskId);
    }
    
    int execTop() {
        //pq : {priority, taskId}
        while(!pq.empty()){
            auto top = pq.top();
            int currP = top.first;
            int currT = top.second;
            pq.pop();
            if (!taskList.count(currT)) continue; // task was removed
            //check if this Priority is latest update one
            int actualP = taskList[currT].first;
            if(taskList.count(currT) && currP==actualP ){
                int ret = taskList[currT].second;
                taskList.erase(currT);
                return ret;
            }
        }
        return -1;
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