string check(Node *root, unordered_map<string,int>&mp,string marker)
{
   
    string s="";
     if(root==NULL)
        return s+marker;
     string lstr=check(root->left,mp,marker);
     if(lstr.compare(s)==0)
        return s;
     string rstr=check(root->right,mp,marker);
     if(rstr.compare(s)==0)
        return s;
     s+=root->data+lstr+rstr;
     
     if(s.length()>3 && mp.find(s)!=mp.end())
        return "";
    
     mp[s]++;
     return s;
}
bool dupSub(Node *root)
{
     string marker="$";
    unordered_map<string,int>mp;
    string s=check(root,mp,marker);
    
    if(s=="")
        return true;
    else
        return false;
     
}
