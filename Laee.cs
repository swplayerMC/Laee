using System;
using System.Text.RegularExpressions;

namespace Laee
{
  class Laee
  {
    public static void Run(string laeCode)
    {
      string functionPattern = @"(?:^|\s+)(\w+)\((?s).*\)";
      Console.WriteLine("Found functions:");
      MatchCollection functions = Regex.Matches(laeCode, functionPattern);
      foreach (Match func in functions)
      {
	Console.WriteLine(func.Value);
      }
    }
  }
}
