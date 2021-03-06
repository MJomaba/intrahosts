args <- commandArgs(TRUE) ;
outdir<-args[1]
datadir<- args[2] ;
library("ape") ;
library("phangorn") ;
source("cSIRmain.R") ;
source("cSIRio.R") 
source("phylo.R")
dyn.load("cSIR.so") ;

set.seed(10000)
# load in data
load(file=paste(datadir,"/dat.RData",sep="")) ;
seqs<-dnaBINmxtolist(datadir)
#seqs<-read.dna(as.character=TRUE, paste(datadir,"/test.dat",sep=""))
#load(file=paste(datadir,"/seqs.RData",sep="")) ;

#dat$SN<-10 ;
#dat$ST<-dat$ST[1] ;
#dat$info[[1]]$key<-dat$info[[1]]$key[1:10] ;

#dat$SN<-dat$SN[1:20] ;
#dat$ST<-dat$ST[1:20] ;
#dat$info<-dat$info[1:20] ;
#dat$info<-dat$info[[1]] ;

NHosts<-length(dat$SN) ;

# Initialisation
# convert sequences to class PhyBin
#x<-phyDat(seqs[1:sum(dat$SN)]) ;


# calculate UPGMA tree for each within-host population



system.time(smp<-cSIR_SB_metrop2(nHosts=NHosts,I0=1,nS=1000,dr=1,dat=dat,x=seqs,N=10000))
#save(smp,file=paste(outdir,"/out.mcmc",sep="")) ;
vars<-c("mr","dr","B","ll","tr")
for (i in seq(1,length(vars)))
{
	assign(vars[i],smp[[vars[i]]])
	save(list=vars[i],file=paste(outdir,"/",vars[i],".mcmc",sep="")) ;
}
warnings()
q()

