module A5(
input  wire u,
input  wire v,
output wire redled,
output wire greenled,
output wire blueled
);

reg x,y;
always @(*)
begin
x=(u&v)|(!u&v)|(!u&!v);
y= (!u)|v;
if(x==1)
begin
redled=1;
end
else
begin
redled=0;
end
if(y==1)
begin
greenled=1;
end
else
begin
greenled=0;
end
if(x==y)
begin
blueled=1;
end
else
begin
blueled=0;
end
end
endmodule