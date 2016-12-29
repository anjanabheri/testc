#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int compare(const void* a, const void* b)
{
    if (*((char *) a) < *((char *) b))
        return -1;
    else
        return 1;
}

int main()
{
    char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);

    int lena = strlen(a);
    int lenb = strlen(b);

    int maxlen = lena > lenb ? lena : lenb;

    qsort(a, lena, sizeof(char), compare);
    qsort(b, lenb, sizeof(char), compare);

    int i = 0;
    int j = 0;
    int count = 0;

    while (i < lena && j < lenb)
    {
        if (a[i] < b[j])
        {
            count ++;
            i ++;
        }
        else if (a[i] > b[j])
        {
            count ++;
            j ++;
        }
        else
        {
            i ++;
            j ++;
        }
    }

    if (i < j)
        count += strlen(a) - i;
    else if (i > j)
        count += strlen(b) - j;

    printf("\nto delete: %d\n", count);

    return 0;
}

/*

Expected output: 1000, but it's coming 968
Input:


zjadbkhmquvpcedlhsarcjzfsnekawczfccjomvfirwkvbveuvvwgwdbkklmgnlorpxgdunmnjwkksoepjdwiixssigbytppioxoikcwtyggsvmigrgoadisnovlhkdsacgjpkhiinqdkdnruvhwyqrngmbozgiziqkxarikfyprdciazswxinnqaogzuoaeglcgcmrjmibqnlqmfmkpczgcnmdjddnjorqtfjesthkgvataofqqewutizendrxtlpoqatktauavwtylyodekaxuzbieuhyhwoayhkrkhrhdmfqmtwqfwpcxsmcntcwrqwpajikqctvobmduivcgleddqfslhreyntaydkqffmwgazdkuhqhltndbfqkyukmpkmswdycrukrvnbpurxhmkmprcaqykenvsgtvgvocgfxvgmqzlzoxmdrofjnqncnfkgdqersmzrhhgzhrzxrlcibirqagtnndvswbkqnlivsoubhvyygdgilzylftatxxlvzxloktldjierdfpkkyuvzuifokanhniinvzxrkcasjrwojiajcvkwfpmprzyhjjwfitwswylfqjvbrvmvswtxogohhmorvkydgwyeullmuipndbixybwojkvrwmkuykxegxicivpedergizfidbwmlrdkfpeezdihbtklobqsfhapjixmjtyxnehsvlyvqjcrcodsptmxcnmlxkxgfydsemnzxlwquzjypmrfhfcmuoxraxygvdyzqnapzxfvypundnsnswznnyenvetqiurahspirxepoacrpxghvfwigdwbjrurlntthldyihnyjqpypygkfevljrntkjmwwgreruebesznkqmzouluagfkzudkfpgexziotorxgqlqjzrxtdttlbdlxivdydhvcrmxffvmwiehjyecbyxobdzylwblzkjdbxbhcyvaibhrzovcosrpxsnlppwqzhudgxmjvjldktumhpqvjhkhczstqqjqafvgchrxsdccyyqfnhczqogsnalesxwsctbfaueuxjwxhpevwguowcjkewqwtorwhsdjojdmsbjasqxowtftvofzkxxenocuihfxqilllwnemkujdzeaplbckygxnktxtyulifwvcjzotwzyxdapqbrcazzpjsmcsjncomyqvzhrvgrvmsketbhvagklbznvicyyqwpmvyftewosqyxkzefzmsmntbjddhbwfskaqptxnhpehmqgqvhdptskubnakpwpjisaxlzmvoqcbglreuwvqpgmsvofkmuwumytaxgxlybmhmgljeibvonoketwqpunesggpmddleputxhcepfzgsnsyiqpalcgdimvxpykvpeoplstcxsiqiaostfsejyjukgrbgdxwhlnuggwdahvijmbcrvidwuxgaqkhtjfcuswaaugadbjnnmrhhakduhmwxydqhkudcsgemmfsnqfbcyilaspwbdtybyqkjknnctsqfxitnpwrqgcqatnbwibzgtlpfzfjsxzawkvlbrcrxekzaxayhdynwjfdkkmfjlffxasbtussaeradtzkyzywkdzxplcywjfwlxxetryvwrwzmxkkykgkpfheqjcoshmfgjlzdjuzasaormypwealljpdttsncgtiqgjtqgusyuhsjhjfojtzvkdoexdidyrvfcqxikpjhydqgmxuyqvtdyjhxmrdnkyunprxbiikhlapyajwsepvfaeemwhbgivvzotaxbngnpvnpgjimafrakyoifsonnkoefrbgehvteilktvwvaqvkomuvejltvzxcqykwhisnqdzmywhyoflerfbxqmqnoorgocdykvlcaloyjyyzdlfwtgtltlzhbsnqusqgpdjpqzpbxqacbfyumtghfhqgzfywyqcpunfknwommorqwrmknutsdjadobbmrfeltlyihmwwcnmahakuvdoyooddrerjkvwfgwnoijmnza
ngaacvfquugxxyeqjomftsciimruzswpaxrcswuosbmpbqgkgupbmtjxgcthvqwxnnchmwwexkwyaeiiyajmtujzwfjtvfrkvtrhrplpzjpbnajlauavojxlogglnzviuprmefbeosfcsrpulpqabnnrttdivarpribwnecexjgraxmoneqqrfhmymutnnlgymcnrgrqszhuxvimzacsflggybznqmtozycseviwvrrspbgqcijhtpntspgjbazcyduczebuyuonvudxcofxeuryjxhlzjpxmkcloffoztduphstvzrbvkafjjsjshihtkskpayovclllfeigxkbhmgrxacskkzdvtnmtmdpqocbtgjzevaljjehlgzvrazotmcnafeqtgroodpsaqgkbmtmtuimujcpvecykiofoiudnlxnbdzesutlodzkmdajhehtnwbdgxitiggmliqdclqtordaudmektxxryazxjsgrbsejkilwaeksknopbszuqwoqznqkiwdjohsarfwsmhmwwanxtntlljdmztwhpbqfjkgapeudngzjhnicccnnnsammyvdalljxtlnxgqloswxhfzjjoyyjylvzgabunmrgxggfztwrptawvjhljguktrjbskxhwrovxwdypzpeurdpckbmsxwnpfpjroqpfgkdcnbtotajmdyppbbkzxxqeozxdrmiayneorycmynydonspqcqpcitqhstbeebftftkdxydlxgzmzqddjufroybitcnxfurmndsmcvzbcandrsganotdmulhyaffuysjdkyffxgjywmpqvrdlmizhwghwnntnherrcyyahkydypvvibgujhdfonedazrjdkagiagpkgulvqgfrnbcufkksoqunhdqrfybheruklfhdlowaqzxxjjpzzloiqgbxfdglwayjhhnvwjxokwlvgcwhnksftvcaaklwlliutvrrgpftlqotsldhxxmqsq
*/
