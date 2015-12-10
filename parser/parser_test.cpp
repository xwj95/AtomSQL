/*
 * parser_test.cpp: Test the parser
 * 
 * Huang Huan
 * CST, Tsinghua University
 */

//
// Global PF_Manager and RM_Manager variables
//
PF_Manager pfm;
RM_Manager rmm(pfm);
IX_Manager ixm(pfm);
SM_Manager smm(ixm, rmm);
QL_Manager qlm(smm, ixm, rmm);

int main(void)
{
    RC rc;

    if ((rc = smm.OpenDb("testdb"))) {
        PrintError(rc);
        return (1);
    }

    RBparse(pfm, smm, qlm);

    if ((rc = smm.CloseDb())) {
        PrintError(rc);
        return (1);
    }
}
