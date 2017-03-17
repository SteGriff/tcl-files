Option Strict On
Imports System.Math

Module DecimalToFraction1

    Sub Main()

        Do

            Dim Input As Double = Double.Parse(Console.ReadLine)
            Console.WriteLine(CFraction(CDec(Input)))

        Loop


    End Sub

    Function CFraction(ByVal aDecimal As Decimal) As String

        Dim Numerator, Denominator As Long
        Numerator = 1

        Denominator = CLng(Reciprocate(aDecimal, Numerator, 0))
        Return (Numerator.ToString & "/" & Denominator.ToString)

    End Function

    Function Reciprocate(ByVal input As Decimal, ByRef Numerator As Long, ByVal depth As Integer) As Decimal

        depth += 1
        Dim Acc As Integer = 13

        Dim This As Decimal = Numerator / input

        If CLng(This) = Round(This, Acc) Then
            Return CLng(This)
        ElseIf depth >= 7 Then
            Console.WriteLine("Recurring decimal didn't have enough accuracy.")
            Return This
        Else
            Dim FractionPart As Decimal = This - Floor(This)
            Numerator = CLng(Reciprocate(FractionPart, Numerator, depth))
            Return This * Numerator
        End If

    End Function

End Module
