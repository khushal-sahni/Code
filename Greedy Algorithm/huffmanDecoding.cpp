string decode_file(struct MinHeapNode* root, string s)
{
  string ans = "";
  for(int i = 0; i < s.length(); ){
    auto node = root;
    while(node->data == '$'){
      if(s[i] == '0') node = node->left;
      else node = node->right;
      i++;
    }
    ans += (node->data);
  }
  return ans;
}
