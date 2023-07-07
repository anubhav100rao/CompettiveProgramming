
import java.util.*;

public class Main{
    public static void main(String[] args)
    {
        int n,f;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        f=in.nextInt();

        int k[]=new int[n];
        int l[]=new int[n];

        for(int i=0;i<n;i++)
        {
            k[i]=in.nextInt();
            l[i]=in.nextInt();
        }

        Solution obj=new Solution();

        obj.solve(k,l,n,f);
        in.close();
    }
}

class Node {
    long gain;
    long original;
    long index;
    Node(long gain, long original, long index) {
        this.gain = gain;
        this.original = original;
        this.index = index;
    }

    @Override
    public String toString() {
        return gain + " " + original + " " + index;
    }
}

class Solution{

    public void solve(int k[],int l[],int n,int f)
    {
        ArrayList<Node>arrayList = new ArrayList<>();
        for(int i = 0; i < n; i++)
            arrayList.add(new Node(Math.min(2 * k[i], l[i]) - Math.min(k[i], l[i]), Math.min(k[i], l[i]), i));

        Collections.sort(arrayList, (a, b) -> {
            if(a.gain == b.gain) {
                return (int)(a.original - b.original);
            }
            return (int)(b.gain - a.gain);
        });

        long ans = 0;
        HashSet<Integer>taken = new HashSet<>();
        for(int i = 0; i < f; i++) {
            int index = (int)arrayList.get(i).index;
            taken.add(index);
            ans += Math.min(2 * k[index], l[index]);
        }

        for(int i = 0; i < n; i++) {
            if(!taken.contains(i)) {
                ans += Math.min(k[i], l[i]);
            }
        }

        
        System.out.println(ans);

    }
}