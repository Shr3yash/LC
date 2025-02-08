class NumberContainers {
    // ArrayList<Integer> container;  
    private Map<Integer, Integer> container;

public NumberContainers() {
    container = new HashMap<>();  
}

public void change(int index, int number) {
    container.put(index, number);
    // while (container.size() <= index) {
    //     container.add(0); 
    //     // Ensure the ArrayList is large enough to accommodate the index
    // }
    // container.set(index, number);
}

public int find(int number) {
    int returnSmallestIdx = Integer.MAX_VALUE;
    for(Map.Entry<Integer, Integer> itr : container.entrySet()){
        if(itr.getValue() == number && itr.getKey()<returnSmallestIdx){
            returnSmallestIdx = itr.getKey();
        }
    }
    return returnSmallestIdx == Integer.MAX_VALUE ? -1 : returnSmallestIdx;
}
}

/**
* Your NumberContainers object will be instantiated and called as such:
* NumberContainers obj = new NumberContainers();
* obj.change(index,number);
* int param_2 = obj.find(number);
*/