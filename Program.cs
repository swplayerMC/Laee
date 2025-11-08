using System;
using System.Text.RegularExpressions;

namespace Laee
{
  class Program
  {
    static void Main(string[] args)
    {
      /* Comments are every text after first '<>' and before line end, like:
       * <> This is a comment
       * or anything between '--[' and ']--' like
       * --[
       *  this is a multi-line comment
       * ]--
       * And the line should end after ']--' but it's not obligatory. */
      //string comments = @"(--\[[^\]\-\-]*\]--)|(--[^\n]*)"; // MultiLine --[]--
      //string comments = @"(--\[\[[^\]\]]*\]])|(--[^\n]*)"; // MultiLine --[[]]
      string comments = @"<>[^\n]*|<<>[^<>>]*<>>";
      string laeCode = args.Length > 0 ? File.ReadAllText(args[0]) : "";
      // Regex re;
      Console.WriteLine(Regex.Replace(laeCode, comments, string.Empty));
      Laee.Run(laeCode);
    }
  }
}
