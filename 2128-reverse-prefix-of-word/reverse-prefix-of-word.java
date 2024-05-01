class Solution {
    public String reversePrefix(String word, char ch) {
        int j = word.indexOf(ch);

        if (j != -1) 
        {
            StringBuilder st = new StringBuilder(word.substring(0, j+1));
            st.reverse();
            return st.toString() + word.substring(j+1);
            
        }

        return word;

  
    }
}