#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preInPreorderInOne(Node* root){
    vector<int> preorder, inorder, postorder;
    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty()){

        auto it = st.top();
        st.pop();

        if(it.second == 1){            
            preorder.push_back(it.first -> data);
            it.second++;
            st.push(it);
            if(it.first -> left != NULL){
                st.push({it.first -> left, 1});
            }
        }
        else if(it.second == 2){            
            inorder.push_back(it.first -> data);
            it.second++;
            st.push(it);
            if(it.first -> right != NULL){
                st.push({it.first -> right, 1});
            }
        }
        else{
            postorder.push_back(it.first -> data);
        }
    }

    cout<<"PREORDER TRAVERSAL:\n";
    for(int i = 0; i < preorder.size(); i++){
        cout<<preorder[i]<<" ";
    }
    cout<<"\nINORDER TRAVERSAL:\n";
    for(int i = 0; i < inorder.size(); i++){
        cout<<inorder[i]<<" ";
    }
    cout<<"\nPOSTORDER TRAVERSAL:\n";
    for(int i = 0; i < postorder.size(); i++){
        cout<<postorder[i]<<" ";
    }
}

int main(){

    struct Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */


    preInPreorderInOne(root);

    return 0;
}

int main() {
   // Declaration of a static array with size 5
   int arr[5];

   // Assigning values to the array
   arr[0] = 10;
   arr[1] = 20;
   arr[2] = 30;
   arr[3] = 40;
   arr[4] = 50;

   // Accessing the elements of the array
   for (int i = 0; i < 5; i++) {
      std::cout << arr[i] << " ";
   }
   return 0;
}

public class Main {
   public static void main(String[] args) {
      // Declaration of a static array with size 5
      int[] arr = new int[5];

      // Assigning values to the array
      arr[0] = 10;
      arr[1] = 20;
      arr[2] = 30;
      arr[3] = 40;
      arr[4] = 50;

      // Accessing the elements of the array
      for (int i = 0; i < 5; i++) {
         System.out.print(arr[i] + " ");
      }
   }
}
