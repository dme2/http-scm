/* Generated from pooltest.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.2.0 (rev 317468e4)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: pooltest.scm -output-file pooltest.c
   uses: library eval expand lolevel extras posix data-structures file
*/
#include "chicken.h"

#include "tj.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_lolevel_toplevel)
C_externimport void C_ccall C_lolevel_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_posix_toplevel)
C_externimport void C_ccall C_posix_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externimport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[30];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,11),40,116,101,115,116,45,102,117,110,99,41,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,32),40,105,110,105,116,45,116,104,114,101,97,100,45,112,111,111,108,32,116,104,114,101,97,100,99,111,117,110,116,57,54,41};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,32),40,98,117,105,108,100,45,106,111,98,45,110,111,100,101,32,102,117,110,99,49,48,50,32,97,114,103,115,49,48,51,41};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,27),40,98,117,105,108,100,45,106,111,98,45,110,111,100,101,45,110,112,32,102,117,110,99,49,49,52,41,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,24),40,101,110,113,117,101,117,101,45,106,111,98,32,113,49,50,50,32,106,110,49,50,51,41};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,16),40,103,101,116,45,113,117,101,117,101,32,112,49,51,51,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,17),40,100,114,97,105,110,45,112,111,111,108,32,112,49,52,49,41,0,0,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,16),40,112,111,111,108,45,119,97,105,116,32,112,49,52,56,41};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,11),40,116,101,115,116,45,112,111,111,108,41,0,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,49,54,55,41,0,0,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,14),40,116,101,115,116,45,113,117,101,117,101,32,112,41,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub149(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
struct pool *p=(struct pool *)C_c_pointer_or_null(C_a0);
poolWait(p);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub142(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
struct pool *p=(struct pool *)C_c_pointer_or_null(C_a0);
drainPool(p);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer_or_false(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub134(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
struct pool *p=(struct pool *)C_c_pointer_or_null(C_a0);
C_return(p->queue);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub124(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
struct job_queue *q=(struct job_queue *)C_c_pointer_or_null(C_a0);
struct job_node *jn=(struct job_node *)C_c_pointer_or_null(C_a1);
int err = enqueueJob(q,jn); C_return(err);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer_or_false(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub115(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void  (*func)()=(void  (*)())C_c_pointer_or_null(C_a0);
job_node* job = buildJobNode((void*)func, NULL); C_return(job);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer_or_false(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub104(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * func=(void * )C_c_pointer_or_null(C_a0);
void * args=(void * )C_c_pointer_or_null(C_a1);
job_node* job = buildJobNode((void*)func, args); C_return(job);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer_or_false(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub97(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int threadcount=(int )C_unfix(C_a0);
pool* p = initPool(threadcount); C_return(p);
C_ret:
#undef return

return C_r;}

C_noret_decl(f_320)
static void C_ccall f_320(C_word c,C_word *av) C_noret;
C_noret_decl(f_323)
static void C_ccall f_323(C_word c,C_word *av) C_noret;
C_noret_decl(f_326)
static void C_ccall f_326(C_word c,C_word *av) C_noret;
C_noret_decl(f_329)
static void C_ccall f_329(C_word c,C_word *av) C_noret;
C_noret_decl(f_332)
static void C_ccall f_332(C_word c,C_word *av) C_noret;
C_noret_decl(f_335)
static void C_ccall f_335(C_word c,C_word *av) C_noret;
C_noret_decl(f_338)
static void C_ccall f_338(C_word c,C_word *av) C_noret;
C_noret_decl(f_341)
static void C_ccall f_341(C_word c,C_word *av) C_noret;
C_noret_decl(f_344)
static void C_ccall f_344(C_word c,C_word *av) C_noret;
C_noret_decl(f_347)
static void C_ccall f_347(C_word c,C_word *av) C_noret;
C_noret_decl(f_350)
static void C_ccall f_350(C_word c,C_word *av) C_noret;
C_noret_decl(f_352)
static void C_ccall f_352(C_word c,C_word *av) C_noret;
C_noret_decl(f_356)
static void C_ccall f_356(C_word c,C_word *av) C_noret;
C_noret_decl(f_363)
static void C_ccall f_363(C_word c,C_word *av) C_noret;
C_noret_decl(f_380)
static void C_ccall f_380(C_word c,C_word *av) C_noret;
C_noret_decl(f_390)
static void C_ccall f_390(C_word c,C_word *av) C_noret;
C_noret_decl(f_407)
static void C_ccall f_407(C_word c,C_word *av) C_noret;
C_noret_decl(f_417)
static void C_ccall f_417(C_word c,C_word *av) C_noret;
C_noret_decl(f_427)
static void C_ccall f_427(C_word c,C_word *av) C_noret;
C_noret_decl(f_437)
static void C_ccall f_437(C_word c,C_word *av) C_noret;
C_noret_decl(f_441)
static void C_ccall f_441(C_word c,C_word *av) C_noret;
C_noret_decl(f_444)
static void C_ccall f_444(C_word c,C_word *av) C_noret;
C_noret_decl(f_447)
static void C_ccall f_447(C_word c,C_word *av) C_noret;
C_noret_decl(f_450)
static void C_ccall f_450(C_word c,C_word *av) C_noret;
C_noret_decl(f_454)
static void C_ccall f_454(C_word c,C_word *av) C_noret;
C_noret_decl(f_456)
static void C_ccall f_456(C_word c,C_word *av) C_noret;
C_noret_decl(f_462)
static void C_fcall f_462(C_word t0,C_word t1) C_noret;
C_noret_decl(f_472)
static void C_ccall f_472(C_word c,C_word *av) C_noret;
C_noret_decl(f_475)
static void C_ccall f_475(C_word c,C_word *av) C_noret;
C_noret_decl(f_482)
static void C_ccall f_482(C_word c,C_word *av) C_noret;
C_noret_decl(f_485)
static void C_ccall f_485(C_word c,C_word *av) C_noret;
C_noret_decl(f_488)
static void C_ccall f_488(C_word c,C_word *av) C_noret;
C_noret_decl(f_491)
static void C_ccall f_491(C_word c,C_word *av) C_noret;
C_noret_decl(f_494)
static void C_ccall f_494(C_word c,C_word *av) C_noret;
C_noret_decl(f_501)
static void C_ccall f_501(C_word c,C_word *av) C_noret;
C_noret_decl(f_504)
static void C_ccall f_504(C_word c,C_word *av) C_noret;
C_noret_decl(f_510)
static void C_ccall f_510(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_462)
static void C_ccall trf_462(C_word c,C_word *av) C_noret;
static void C_ccall trf_462(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_462(t0,t1);}

/* k318 */
static void C_ccall f_320(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_320,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_323,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k321 in k318 */
static void C_ccall f_323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_323,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_326,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k324 in k321 in k318 */
static void C_ccall f_326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_326,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_329,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_lolevel_toplevel(2,av2);}}

/* k327 in k324 in k321 in k318 */
static void C_ccall f_329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_329,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_332,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_332(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_332,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_335,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_posix_toplevel(2,av2);}}

/* k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_335,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_338,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_338,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_341,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_341,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_344,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("pooltest.scm:1: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[22]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=t2;
av2[2]=lf[28];
av2[3]=lf[29];
av2[4]=lf[25];
tp(5,av2);}}

/* k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_344(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_344,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_347,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("pooltest.scm:10: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[22]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=t2;
av2[2]=lf[26];
av2[3]=lf[27];
av2[4]=lf[25];
tp(5,av2);}}

/* k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_347,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_350,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("pooltest.scm:11: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[22]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=t2;
av2[2]=lf[23];
av2[3]=lf[24];
av2[4]=lf[25];
tp(5,av2);}}

/* k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_350(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,4)))){
C_save_and_reclaim((void *)f_350,c,av);}
a=C_alloc(30);
t2=C_mutate((C_word*)lf[0]+1 /* (set! test-func ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_352,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_set_block_item(lf[2] /* threadcount */,0,C_fix(2));
t4=C_mutate((C_word*)lf[3]+1 /* (set! init-thread-pool ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_356,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[4]+1 /* (set! build-job-node ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_363,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[5]+1 /* (set! build-job-node-np ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_380,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[6]+1 /* (set! enqueue-job ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_390,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[7]+1 /* (set! get-queue ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_407,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[8]+1 /* (set! drain-pool ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_417,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[9]+1 /* (set! pool-wait ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_427,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[10]+1 /* (set! test-pool ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_437,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_454,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("pooltest.scm:73: test-pool"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2=av;
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t12;
tp(2,av2);}}

/* test-func in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_352,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[1];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* init-thread-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_356,c,av);}
a=C_alloc(5);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub97(t3,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* build-job-node in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_363,c,av);}
a=C_alloc(5);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t6=(C_truep(t3)?C_i_foreign_pointer_argumentp(t3):C_SCHEME_FALSE);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=stub104(t4,t5,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* build-job-node-np in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_380,c,av);}
a=C_alloc(5);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=stub115(t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* enqueue-job in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_390(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_390,c,av);}
t4=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t5=(C_truep(t3)?C_i_foreign_pointer_argumentp(t3):C_SCHEME_FALSE);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=stub124(C_SCHEME_UNDEFINED,t4,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* get-queue in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_407,c,av);}
a=C_alloc(5);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=stub134(t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* drain-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_417(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_417,c,av);}
t3=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub142(C_SCHEME_UNDEFINED,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* pool-wait in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_427,c,av);}
t3=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub149(C_SCHEME_UNDEFINED,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* test-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_437,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_441,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("pooltest.scm:67: init-thread-pool"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[3]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t2;
av2[2]=C_fast_retrieve(lf[2]);
tp(3,av2);}}

/* k439 in test-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_441(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_441,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_444,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
C_trace(C_text("pooltest.scm:68: chicken.memory#object->pointer"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t2;
av2[2]=C_fast_retrieve(lf[0]);
tp(3,av2);}}

/* k442 in k439 in test-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_444(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_444,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[11]+1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_447,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
C_trace(C_text("pooltest.scm:69: ##sys#check-output-port"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t3;
av2[2]=*((C_word*)lf[11]+1);
av2[3]=C_SCHEME_TRUE;
av2[4]=lf[15];
tp(5,av2);}}

/* k445 in k442 in k439 in test-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_447(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_447,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_450,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
C_trace(C_text("pooltest.scm:69: ##sys#print"));
t3=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[13];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k448 in k445 in k442 in k439 in test-pool in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_450(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_450,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_454(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_454,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[17]+1 /* (set! pool ...) */,t1);
t3=C_mutate((C_word*)lf[18]+1 /* (set! test-queue ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_456,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_504,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("pooltest.scm:87: test-queue"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[18]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t4;
av2[2]=C_fast_retrieve(lf[17]);
tp(3,av2);}}

/* test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_456,c,av);}
a=C_alloc(10);
t3=C_fix(0);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_462,a[2]=t4,a[3]=t6,a[4]=t2,a[5]=((C_word)li9),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_462(t8,t1);}

/* loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_fcall f_462(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_462,2,t0,t1);}
a=C_alloc(7);
if(C_truep(C_i_lessp(((C_word*)((C_word*)t0)[2])[1],C_fix(1)))){
t2=*((C_word*)lf[11]+1);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_472,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=t2,tmp=(C_word)a,a+=7,tmp);
C_trace(C_text("pooltest.scm:79: ##sys#check-output-port"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t3;
av2[2]=*((C_word*)lf[11]+1);
av2[3]=C_SCHEME_TRUE;
av2[4]=lf[15];
tp(5,av2);}}
else{
t2=t1;{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_472(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_472,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_475,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
C_trace(C_text("pooltest.scm:79: ##sys#print"));
t3=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[20];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,2)))){
C_save_and_reclaim((void *)f_475,c,av);}
a=C_alloc(34);
t2=C_s_a_i_plus(&a,2,((C_word*)((C_word*)t0)[2])[1],C_fix(1));
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_482,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
C_trace(C_text("pooltest.scm:82: chicken.memory#object->pointer"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t4;
av2[2]=C_fast_retrieve(lf[0]);
tp(3,av2);}}

/* k480 in k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_482,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_485,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
C_trace(C_text("pooltest.scm:83: build-job-node-np"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[5]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t2;
av2[2]=C_fast_retrieve(lf[0]);
tp(3,av2);}}

/* k483 in k480 in k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_485(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_485,c,av);}
a=C_alloc(7);
t2=*((C_word*)lf[11]+1);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_488,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=t2,tmp=(C_word)a,a+=7,tmp);
C_trace(C_text("pooltest.scm:84: ##sys#check-output-port"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t3;
av2[2]=*((C_word*)lf[11]+1);
av2[3]=C_SCHEME_TRUE;
av2[4]=lf[15];
tp(5,av2);}}

/* k486 in k483 in k480 in k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_488,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_491,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
C_trace(C_text("pooltest.scm:84: ##sys#print"));
t3=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[19];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k489 in k486 in k483 in k480 in k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_491(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_491,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_494,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_501,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
C_trace(C_text("pooltest.scm:85: get-queue"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[7]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}

/* k492 in k489 in k486 in k483 in k480 in k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_494(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_494,c,av);}
C_trace(C_text("pooltest.scm:78: loop167"));
t2=((C_word*)((C_word*)t0)[2])[1];
f_462(t2,((C_word*)t0)[3]);}

/* k499 in k489 in k486 in k483 in k480 in k473 in k470 in loop167 in test-queue in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_501,c,av);}
C_trace(C_text("pooltest.scm:85: enqueue-job"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[6]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k502 in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_504(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_504,c,av);}
a=C_alloc(3);
t2=C_fast_retrieve(lf[8]);
t3=C_fast_retrieve(lf[17]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_510,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("chicken.base#implicit-exit-handler"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[21]);
C_word *av2=av;
av2[0]=*((C_word*)lf[21]+1);
av2[1]=t4;
tp(2,av2);}}

/* k508 in k502 in k452 in k348 in k345 in k342 in k339 in k336 in k333 in k330 in k327 in k324 in k321 in k318 */
static void C_ccall f_510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_510,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;
C_main_entry_point

void C_ccall C_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("toplevel"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(191))){
C_save(t1);
C_rereclaim2(191*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,30);
lf[0]=C_h_intern(&lf[0],9, C_text("test-func"));
lf[1]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007hello!\012"));
lf[2]=C_h_intern(&lf[2],11, C_text("threadcount"));
lf[3]=C_h_intern(&lf[3],16, C_text("init-thread-pool"));
lf[4]=C_h_intern(&lf[4],14, C_text("build-job-node"));
lf[5]=C_h_intern(&lf[5],17, C_text("build-job-node-np"));
lf[6]=C_h_intern(&lf[6],11, C_text("enqueue-job"));
lf[7]=C_h_intern(&lf[7],9, C_text("get-queue"));
lf[8]=C_h_intern(&lf[8],10, C_text("drain-pool"));
lf[9]=C_h_intern(&lf[9],9, C_text("pool-wait"));
lf[10]=C_h_intern(&lf[10],9, C_text("test-pool"));
lf[11]=C_h_intern(&lf[11],21, C_text("##sys#standard-output"));
lf[12]=C_h_intern(&lf[12],11, C_text("##sys#print"));
lf[13]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015pool started\012"));
lf[14]=C_h_intern(&lf[14],23, C_text("##sys#check-output-port"));
lf[15]=C_h_intern(&lf[15],6, C_text("printf"));
lf[16]=C_h_intern(&lf[16],30, C_text("chicken.memory#object->pointer"));
lf[17]=C_h_intern(&lf[17],4, C_text("pool"));
lf[18]=C_h_intern(&lf[18],10, C_text("test-queue"));
lf[19]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014queuing job\012"));
lf[20]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005loop\012"));
lf[21]=C_h_intern(&lf[21],34, C_text("chicken.base#implicit-exit-handler"));
lf[22]=C_h_intern(&lf[22],27, C_text("chicken.load#load-extension"));
lf[23]=C_h_intern(&lf[23],7, C_text("srfi-13"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\010\001srfi-13#\376\377\016"));
lf[25]=C_h_intern(&lf[25],7, C_text("require"));
lf[26]=C_h_intern(&lf[26],4, C_text("bind"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\005\001bind#\376\377\016"));
lf[28]=C_h_intern(&lf[28],12, C_text("simple-loops"));
lf[29]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\015\001simple-loops#\376\377\016"));
C_register_lf2(lf,30,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_320,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[39] = {
{C_text("f_320:pooltest_2escm"),(void*)f_320},
{C_text("f_323:pooltest_2escm"),(void*)f_323},
{C_text("f_326:pooltest_2escm"),(void*)f_326},
{C_text("f_329:pooltest_2escm"),(void*)f_329},
{C_text("f_332:pooltest_2escm"),(void*)f_332},
{C_text("f_335:pooltest_2escm"),(void*)f_335},
{C_text("f_338:pooltest_2escm"),(void*)f_338},
{C_text("f_341:pooltest_2escm"),(void*)f_341},
{C_text("f_344:pooltest_2escm"),(void*)f_344},
{C_text("f_347:pooltest_2escm"),(void*)f_347},
{C_text("f_350:pooltest_2escm"),(void*)f_350},
{C_text("f_352:pooltest_2escm"),(void*)f_352},
{C_text("f_356:pooltest_2escm"),(void*)f_356},
{C_text("f_363:pooltest_2escm"),(void*)f_363},
{C_text("f_380:pooltest_2escm"),(void*)f_380},
{C_text("f_390:pooltest_2escm"),(void*)f_390},
{C_text("f_407:pooltest_2escm"),(void*)f_407},
{C_text("f_417:pooltest_2escm"),(void*)f_417},
{C_text("f_427:pooltest_2escm"),(void*)f_427},
{C_text("f_437:pooltest_2escm"),(void*)f_437},
{C_text("f_441:pooltest_2escm"),(void*)f_441},
{C_text("f_444:pooltest_2escm"),(void*)f_444},
{C_text("f_447:pooltest_2escm"),(void*)f_447},
{C_text("f_450:pooltest_2escm"),(void*)f_450},
{C_text("f_454:pooltest_2escm"),(void*)f_454},
{C_text("f_456:pooltest_2escm"),(void*)f_456},
{C_text("f_462:pooltest_2escm"),(void*)f_462},
{C_text("f_472:pooltest_2escm"),(void*)f_472},
{C_text("f_475:pooltest_2escm"),(void*)f_475},
{C_text("f_482:pooltest_2escm"),(void*)f_482},
{C_text("f_485:pooltest_2escm"),(void*)f_485},
{C_text("f_488:pooltest_2escm"),(void*)f_488},
{C_text("f_491:pooltest_2escm"),(void*)f_491},
{C_text("f_494:pooltest_2escm"),(void*)f_494},
{C_text("f_501:pooltest_2escm"),(void*)f_501},
{C_text("f_504:pooltest_2escm"),(void*)f_504},
{C_text("f_510:pooltest_2escm"),(void*)f_510},
{C_text("toplevel:pooltest_2escm"),(void*)C_toplevel},
{NULL,NULL}};
#endif

static C_PTABLE_ENTRY *create_ptable(void){
#ifdef C_ENABLE_PTABLES
return ptable;
#else
return NULL;
#endif
}

/*
S|applied compiler syntax:
S|  chicken.format#printf		3
o|eliminated procedure checks: 12 
(o e)|assignments to immediate values: 1 
o|propagated global variable: out157160 ##sys#standard-output 
o|propagated global variable: out178181 ##sys#standard-output 
o|propagated global variable: out171174 ##sys#standard-output 
o|replaced variables: 41 
o|removed binding forms: 36 
o|removed binding forms: 32 
o|simplifications: ((if . 8) (##core#call . 11)) 
o|  call simplifications:
o|    scheme#<
o|    scheme#+
o|    ##sys#foreign-pointer-argument	8
o|    ##sys#foreign-fixnum-argument
o|contracted procedure: k359 
o|contracted procedure: k366 
o|contracted procedure: k370 
o|contracted procedure: k383 
o|contracted procedure: k393 
o|contracted procedure: k397 
o|contracted procedure: k410 
o|contracted procedure: k420 
o|contracted procedure: k430 
o|contracted procedure: k467 
o|contracted procedure: k477 
o|simplifications: ((let . 2)) 
o|removed binding forms: 11 
o|customizable procedures: (loop167170) 
o|calls to known targets: 2 
o|fast box initializations: 1 
*/
/* end of file */
