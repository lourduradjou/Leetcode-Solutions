import java.util.HashSet;
import java.util.Set;

public class RandomizedSet {
    private Set<Integer> st;

    public RandomizedSet() {
        st = new HashSet<>();
    }

    public boolean insert(int val) {
        // val should not already be there in the set
        if (st.contains(val))
            return false;
        st.add(val);
        return true;
    }

    public boolean remove(int val) {
        // val should be there to remove
        if (!st.contains(val))
            return false;
        st.remove(val);
        return true;
    }

    public int getRandom() {
        int randomIndex = (int) (Math.random() * st.size());
        Integer[] array = st.toArray(new Integer[0]);
        return array[randomIndex];
    }

    public static void main(String[] args) {
        RandomizedSet obj = new RandomizedSet();
        boolean param_1 = obj.insert(1);
        boolean param_2 = obj.remove(2);
        int param_3 = obj.getRandom();
    }
}
