#!/usr/bin/perl -w
## test.pl for test in /home/kiinder/assembla_project_42sh/unit_tests
## 
## Made by roger ingouacka
## Login   <ingoua_r@epitech.net>
## 
## Started on  Fri May  6 14:22:29 2011 roger ingouacka
## Last update Sat May 25 18:58:51 2013 louis-philippe baron
##

use strict;

sub		nb_lignes
{
    my ($res)=0;
    open(FIC,"<$ARGV[0]") or die("\nVeuillez passez en arguments un fichier test \n$!");
    while (<FIC>) { $res++; }
    close(FIC);
    return ($res);
}

sub		recup_test
{
    if ( ! open(FIC,"<$ARGV[0]") )
    {
	exit (1);
    }
    my @t = <FIC>;
    close(FIC);
    return (@t);
}

sub		exec_test
{
    my ($nb_lignes)=@_;
    my @info = recup_test();
    open(FIC, "+>SUCCEED") or die "Impoosible to open SUCCEED file\n";
    if (!open(FAC,"+>FAILED") )
    {
	exit (1);
    }
    for (my $x=0;  $x < $nb_lignes; $x++ )
    {
	my $shell0 = `echo '$info[$x]' > tmp/out0; ./mysh < tmp/out0`;
	my $shell1 = `echo '$info[$x]' > tmp/out1; tcsh < tmp/out1`;
  	if ($shell0 eq $shell1)
	{
	    print "TEST $x SUCCEED\n";
	    printf( FIC "[$x] %s", $info[$x] );
	}
	else
	{
	    print "TEST $x FAILED\n";
	    printf( FAC "[$x] %s", $info[$x] );
	}
    }
}

sub		moulinette
{
    my ($res)=0;
    my ($total)=@_;
    open(FIC,"<SUCCEED") or die("can't open fichier SUCCEED : $!");
    while (<FIC>) { $res++; }
    close(FIC);
    print "\n\n TEST DONE\n Note final $res/$total\n";
}

my $x = nb_lignes();
exec_test($x);
moulinette($x);
if ($ARGV[0] eq "partie_obligatoire/pipe_test/pipe_tests")
{
    system ("mv","FAILED", "partie_obligatoire/pipe_test/");
    system ("mv","SUCCEED", "partie_obligatoire/pipe_test/");
}
if ($ARGV[0] eq "partie_obligatoire/redir_test/redir_tests")
{
    system ("mv","FAILED", "partie_obligatoire/redir_test/");
    system ("mv","SUCCEED", "partie_obligatoire/redir_test/");
}
if ($ARGV[0] eq "partie_obligatoire/separateur_test/separateur_tests")
{
    system ("mv","FAILED", "partie_obligatoire/separateur_test/");
    system ("mv","SUCCEED", "partie_obligatoire/separateur_test/");
}
if ($ARGV[0] eq "partie_obligatoire/builtins_tests/builtins_test")
{
    system ("mv","FAILED", "partie_obligatoire/builtins_tests/");
    system ("mv","SUCCEED", "partie_obligatoire/builtins_tests/");
}
