/**
 * first line of input is inorder
 * second line of input is postorder
 * read to EOf
 *
 * for each pair of lines output one line , 
 * a array of internal memory of inputed tree.
 *
 * All possible input trees have at most 25 nodes.
 */

#include<cstdio>
#include<cstdlib>

/*****
 *
 * The sequences of the nodes belong to same subtree 
 * (or you can see this as a slince of inorder / postorder sequences
 * which is represented an subtree)
 * always continous but with different order in two different
 * traversal sequences.
 *
 */
void fillTree(int tree[],int rootIndex,
        const int inorder[] , const int postorder[],
        int iBegin , int pBegin , int treeSize)
{
    int iEnd = iBegin + treeSize - 1;
    int pEnd = pBegin + treeSize - 1;
    int root = postorder[pEnd];
    tree[rootIndex] = root;

    if (iBegin < iEnd)
    {
        int rootIndexOfInorder; 
        for (rootIndexOfInorder = iBegin; inorder[rootIndexOfInorder] != root && 
                rootIndexOfInorder < iEnd + 1 ; ++rootIndexOfInorder)
            ;

        int lSize = rootIndexOfInorder - iBegin;
        if (rootIndexOfInorder > iBegin) // If nonempty left subtree
            fillTree(tree, rootIndex * 2 , inorder , postorder, 
                    iBegin , pBegin , lSize);

        if (iEnd > rootIndexOfInorder) // If nonempty right subtree
            fillTree(tree, rootIndex * 2 + 1 , inorder , postorder, 
                    rootIndexOfInorder + 1 , pBegin + treeSize + 1, iEnd - rootIndexOfInorder);
    }
}

int main()
{
    char buf[512];

    while(NULL != fgets(buf,512,stdin))
    {
        int node = 0, numNodes = 0;
        /* tree[0] is unused */
        int tree[26];   
        int inorder[26],postorder[26];

        numNodes = sscanf(buf,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                &(inorder[0]),&(inorder[1]), &(inorder[2]), &(inorder[3]), &(inorder[4]), &(inorder[5]), 
                &(inorder[6]), &(inorder[7]), &(inorder[8]), &(inorder[9]), &(inorder[10]),
                &(inorder[11]),&(inorder[12]),  &(inorder[13]), &(inorder[14]), &(inorder[15]), 
                &(inorder[16]), &(inorder[17]), &(inorder[18]), &(inorder[19]), &(inorder[20]),
                &(inorder[21]),&(inorder[22]),  &(inorder[23]), &(inorder[24]) );

        if (NULL != fgets(buf,512,stdin))
            sscanf(buf,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
                &(postorder[0]),&(postorder[1]), &(postorder[2]), &(postorder[3]), &(postorder[4]), &(postorder[5]), 
                &(postorder[6]), &(postorder[7]), &(postorder[8]), &(postorder[9]), &(postorder[10]),
                &(postorder[11]),&(postorder[12]),  &(postorder[13]), &(postorder[14]), &(postorder[15]), 
                &(postorder[16]), &(postorder[17]), &(postorder[18]), &(postorder[19]), &(postorder[20]),
                &(postorder[21]),&(postorder[22]),  &(postorder[23]), &(postorder[24]));
        else
        {
            fprintf(stderr,"input error!\n");
            exit(1);
        }

        for (int j = 0 ; j < numNodes ; ++j)
            fprintf(stderr, "%d ",inorder[j]);
        fprintf(stderr,"\n");
        for (int j = 0 ; j < numNodes ; ++j)
            fprintf(stderr, "%d ",postorder[j]);
        fprintf(stderr,"\n");

        fillTree(tree,1,inorder,postorder,0,0 , numNodes) ;

        for (int j = 1 ; j <= numNodes ; ++j)
            fprintf(stderr, "%d ",tree[j]);
        fprintf(stderr,"\n");
    }

}
