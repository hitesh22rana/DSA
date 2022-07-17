class Solution {
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int[] ans=new int[queries.length];
       
        for(int i=0;i<queries.length;i++){

            ArrayList<Pair<String,Integer>> hm=new ArrayList<>();
            int ind=queries[i][1];
            for(int j=0;j<nums.length;j++){
                String str=nums[j];
                String temp=str.substring(nums[j].length()-ind,nums[j].length());
                hm.add(new Pair(temp.trim(),j));
                
            }
            
            Collections.sort(hm,(a,b)->a.getKey().compareTo(b.getKey()));
            ans[i]=hm.get(queries[i][0]-1).getValue();
        }
        return ans;
    }
}