class StockSpanner {
    ArrayList<Integer> values = new ArrayList<Integer>();
    public StockSpanner() {
        
    }
    
    public int next(int price) {
        values.add(price);
        
        for(int i = values.size()-1 ; i>=0 ; i--) {
            if(values.get(i) <= price) {
                int cnt = 0;
                
                while(i >= 0 && values.get(i) <= price) {
                    i--;
                    cnt++;
                }
                
                return cnt;
            }
        }
        
        return 1;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */