#include <sys/mman.h>

#define OBF_CALL ".byte	0xeb,0x01,0xe8\n"
#define DBL_JMP ".byte 0x74,0x03,0x75,0x01,0xe8\n"
#define OBF_LONG_JMP ".byte 0x31,0xc0,0x74,0x01,0xea\n"
#define IMP_JMP ".byte 0xeb,0xff,0xc0,0x48\n"

asm(".intel_syntax noprefix\n"
".equ sig9, 0x04030201 \n"
".equ key9, 0x7788 \n"
".equ sig8, 0x14a283b1 \n"
".equ key8, 0x1d97 \n"
".equ sig7, 0xdeadbeef \n"
".equ key7, 0xbfe \n"
".equ sig6, 0x0ddba11 \n"
".equ key6, 0xa55 \n"
".equ sig5, 0xf005ba11 \n"
".equ key5, 0x1ead \n"
".equ sig4, 0xe5ca1ade \n"
".equ key4, 0xbad \n"
".equ sig3, 0xba5eba11 \n"
".equ key3, 0xcab \n"
".equ sig2, 0x7a7700d \n"
".equ key2, 0x700 \n"
".equ sig1, 0xb0071ace \n"
".equ key1, 0xe1f \n"
".equ sig0, 0x0b501e7e \n"
".equ key0, 0x1ee7 \n");

int auth(char * pass) {
  int found = 1;
  int i = 0;
  asm(
"\tlea	eax, start9\n"
OBF_CALL
"\tcmp	DWORD PTR [eax], sig9\n"
"\tjz	start9\n"
"\txor	DWORD PTR [eax], key9\n"
"\tinc	eax\n"
".word 0xefeb\n"
".int sig9\n"
"start9:\n");
  found = found && (pass[i++] == '_a_');
  found = found && (pass[i++] == '_b_');
  found = found && (pass[i++] == '_c_');
  if (!found) return found;
  asm(
OBF_CALL
"\tlea	eax, start8\n"
"loop8:\n"
".word 0x4eb\n"
"\t.int sig9\n"
"\tcmp	DWORD PTR [eax], sig8\n"
"\tjz	start8\n"
"\txor	DWORD PTR [eax], key8\n"
"\tinc	eax\n"
"\tjmp	loop8\n"
".int sig8\n"
"start8:\n");
  found = found && (pass[i++] == '_d_');
  found = found && (pass[i++] == '_e_');
  found = found && (pass[i++] == '_f_');
  if (!found) return found;
  asm(
DBL_JMP
"\tlea	eax, start7\n"
"loop7:\n"
".word 0x4eb\n"
"\t.int sig8\n"
"\tcmp	DWORD PTR [eax], sig7\n"
"\tjz	start7\n"
"\txor	DWORD PTR [eax], key7\n"
"\tinc	eax\n"
"\tjmp	loop7\n"
".int sig7\n"
"start7:\n");
  found = found && (pass[i++] == '_g_');
  found = found && (pass[i++] == '_h_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig7\n");
  found = found && (pass[i++] == '_i_');
  asm(
"\tlea	eax, start6\n"
"loop6:\n"
"\tcmp	DWORD PTR [eax], sig6\n"
"\tjz	start6\n"
"\txor	DWORD PTR [eax], key6\n"
"\tinc	eax\n"
"\tjmp	loop6\n"
".int sig6\n"
"start6:\n");
  found = found && (pass[i++] == '_j_');
  found = found && (pass[i++] == '_k_');
  found = found && (pass[i++] == '_l_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig6\n"
"\tlea	eax, start5\n"
"loop5:\n"
"\tcmp	DWORD PTR [eax], sig5\n"
"\tjz	start5\n"
"\txor	DWORD PTR [eax], key5\n"
"\tinc	eax\n"
"\tjmp	loop5\n"
".int sig5\n"
"start5:\n");
  found = found && (pass[i++] == '_m_');
  found = found && (pass[i++] == '_n_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig5\n");
  found = found && (pass[i++] == '_o_');
  if (!found) return found;
  asm(
OBF_LONG_JMP
"\tlea	eax, start4\n"
"\tcmp	DWORD PTR [eax], sig4\n"
".word 0xd74\n"
"\txor	DWORD PTR [eax], key4\n"
"\tinc	eax\n"
".word 0xefeb\n"
".int sig4\n"
"start4:\n");
  found = found && (pass[i++] == '_p_');
  found = found && (pass[i++] == '_q_');
  found = found && (pass[i++] == '_r_');
  found = found && (pass[i++] == '_s_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig4\n"
"\tlea	eax, start3\n"
"loop3:\n"
"\tcmp	DWORD PTR [eax], sig3\n"
".word 0xd74\n"
"\txor	DWORD PTR [eax], key3\n"
"\tinc	eax\n"
"\tjmp	loop3\n"
".int sig3\n"
"start3:\n");
  found = found && (pass[i++] == '_t_');
  found = found && (pass[i++] == '_u_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig3\n");
  found = found && (pass[i++] == '_v_');
  asm(
"\tlea	eax, start2\n"
"loop2:\n"
"\tcmp	DWORD PTR [eax], sig2\n"
"\tjz	start2\n"
"\txor	DWORD PTR [eax], key2\n"
"\tinc	eax\n"
"\tjmp	loop2\n"
".int sig2\n"
"start2:\n");
  found = found && (pass[i++] == '_w_');
  found = found && (pass[i++] == '_x_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig2\n");
  found = found && (pass[i++] == '_y_');
  asm(
"\tlea	eax, start1\n"
"loop1:\n"
IMP_JMP
"\tcmp	DWORD PTR [eax], sig1\n"
"\tjz	start1\n"
"\txor	DWORD PTR [eax], key1\n"
"\tinc	eax\n"
"\tjmp	loop1\n"
".int sig1\n"
"start1:\n");
  found = found && (pass[i++] == '_z_');
  found = found && (pass[i++] == '_A_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig1\n");
  found = found && (pass[i++] == '_B_');
  if (!found) return found;
  asm(
"\tlea	eax, start0\n"
"loop0:\n"
"\tcmp	DWORD PTR [eax], sig0\n"
"\tjz	start0\n"
"\txor	DWORD PTR [eax], key0\n"
"\tinc	eax\n"
"\tjmp	loop0\n"
".int sig0\n"
"start0:\n");
  found = found && (pass[i++] == '_C_');
  found = found && (pass[i++] == '_D_');
  found = found && (pass[i++] == '_E_');
  found = found && (pass[i++] == '_F_');
  if (!found) return found;
  asm(
".word 0x4eb\n"
"\t.int sig0\n");
  return found;
}

void prep_the_objective() {
  mprotect((void*)((unsigned int)auth & 0xfffff000),0x1000, 7);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    return 1;
  }
  prep_the_objective();
  if (!auth(argv[1])) {
    puts("NOOO!!! YOU DENSE, IRRITATING, MINIATURE BEAST OF BURDEN! \n");
    return 1;
  } else {
    puts("Success! Here is your key:");
    puts(argv[1]);
    return 0;
  }
}
