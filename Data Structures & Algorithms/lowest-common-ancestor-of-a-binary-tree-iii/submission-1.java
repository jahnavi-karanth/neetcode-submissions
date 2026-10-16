/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/

class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        Node p1=p, q1=q;
        while(p1!=q1){
            if(p1==null){
                p1=q;
            }
            else{
                p1=p1.parent;
            }

            if(q1==null){
                q1=p;
            }
            else{
                q1=q1.parent;
            }
        }
        return p1;
    }  
}