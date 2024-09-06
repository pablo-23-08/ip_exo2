void get_ip(char ip[15], char bit_reseau[3]);
void fonct_msr(char ip[15], char br[3], char msr[15], char ip_bin[32], char msr_bin[32]);
void fonct_reseau(char reseau[15], char reseau_bin[32], char ip_bin[32], char msr_bin[32]);
void fonct_broadcast(char broadcast[15], char broadcast_bin[32], char ip_bin[32], char msr_bin[32], char br[3]);
void fonct_nbre_machine(int *nbre_machine, char msr_bin[32]);
void binary(int *nbre, char bin[8]);
void decimal(char bin[8],int *nbre);
void form_bin(char ip[15], char ip_bin[32]);
void form_dec(char ip[15], char ip_bin[32]);
