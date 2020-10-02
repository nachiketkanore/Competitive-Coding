 

//IMP: IF YOU WANT TO FIND SUCH PREFIX WHICH ALSO PRESENT AT END ,EG. ADRYTAD, HERE ITS AD SO DIRECTLY USE WITHOUT USING TO_FIND ...
AS THE WORK OF Z ALGORITHM IS TO FIND HOW MUCH STRING STARTING FROM CURRENT INDEX MATCHES WITH THE PREFIX ... SO THATS WHY INSERTING '$'
ENSURES THE WORK OF PATTERN MATCHING BY ENDING THE MATCH IF WHOLE STRING IS MATCHED

*****NOTE:IF YOU WANT TO FIND IN GIVEN STRING ITS PRESENT IN INDEX FIND.LENGTH()+I AS FIRST CHARACTERS OF Z-ARRAY ARE FIND STRING AND CHARACTER '$'...
vector<ll> zalgo(string to_find,string given)
{
	// if we have to only use given string ====== z[0]=given.length();
    string total="";
    total=to_find;
    total+='$';
    total+=given;
	vector<ll>z(total.size()+2);
    ll l,r; l=r=0;ll tot_len=total.size();
    for(ll i=1;i<tot_len;i++)
    {
        if(r<i)
        {
            l=r=i;
            while(r<tot_len && total[r]==total[r-l])r++;
            z[i]=r-l;r--;
        }
        else
        {
            ll k=i-l;
            if(z[k]<r-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                l=i;
                while(r<tot_len && total[r]==total[r-l])r++;
                z[i]=r-l;r--;
            }
        }         
    }
return z;
}
