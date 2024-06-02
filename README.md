# Hello Qt-World
Es ist einige Zeit her, dass ich ein Teil von dir war und mich mit C++ und Qt beschäftigt habe. Nun ist es an der Zeit mal einiges aufzufrischen. Daher habe ich dieses Projekt erstellt mit folgendem Hintergrund:
1. Die aktuelle Version von [Qt](https://www.qt.io) und sein Ökosystem kennenlernen
2. Schauen wie schnell meine angestaubten C++ Kenntnisse wieder aktiv werden
3. Zeigen wie ich üblicherweise entwickele (soweit das an einem so einfachen Beispiel möglich ist)
4. Meine "Learnings" dokumentieren (basierend auf dem Ansatz *Today I learned (TIL)* wie gesehen bei [Josh Branchaud](https://github.com/jbranchaud/til))

## `.ui` Dateien vs. manuelle Erstellung von Widgets
Meine ersten Schritte mit dem *Qt Creator* und besonders dessen Integration des *Qt Designer*, waren eher holprig. Erstmal finde ich die UI des *Qt Creator* ziemlich "altmodisch". Außerdem merke ich, dass ich damit noch mehr lernen muss. Daher werde ich mich erstmal darauf konzentrieren die UI-Elemente im Code anzulegen. Vielleicht sehe ich dann später, was mir der *Qt Designer* abnimmt bzw. welche Vorteile er hat.

Das geht natürlich nur, weil ich ohne einen Designer o.ä. arbeite. D.h. für die Arbeit in einem Team (insbesondere mit einem dedizierten Designer der sich im coden nicht so auskennt) sollte ich diese Entscheidung definitiv überarbeiten.

## Style-Guide
Grundsätzlich gefällt mir der Ansatz der [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) von Bjarne Stroustrup und Herb Sutter. Allerdings fehlen mir darin ein paar Details beispielsweise im Bereich *Naming*. Daher gehe ich erstmal für mich mit folgenden "Zusätzen" bzw. Fokus:
- Naming (ensure [NL.8 - Use a consistent naming style](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl8-use-a-consistent-naming-style):
  - Local and global variables will be named in lower_case_with_underscores (*snake_case* / [NL.10 - Prefer `underscore_style` names](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl10-prefer-underscore_style-names)).
  - Class member variables (attributes) will be named with a `m_` prefix (allowed according to [NL.5](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl5-avoid-encoding-type-information-in-names)).
  - Class names will be named in capitalized CamelCase.
  - Functions, including class methods, will be named in capitalized CamelCase.
  - Use `ALL_CAPS` for macro names only ([NL.9](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl9-use-all_caps-for-macro-names-only)
  - All names should be descriptive, other than loop counter variables like i (take into account [NL.7 - make length of a name roughly proportional to the length of its scope](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl7-make-the-length-of-a-name-roughly-proportional-to-the-length-of-its-scope)).
- Pointer/References (haven't found a clear definition for this in the Guideline, but this is how most examples are given in the Guideline)
  - Use `int* myPointerToInt` instead of `int *myOtherPointToInt` (and same way for references)
    - Personally I believe the first version makes it clear that the pointer (or reference) is a property of the type ([see here](https://dev.to/codemouse92/cc-pointer-alignment-style-a-justification-13po))

**Wichtig:** Für mich ist folgende Aussage von der [ISO C++ Coding Standard Seite](https://isocpp.org/wiki/faq/coding-standards#coding-std-wars) besonders wichtig:
> A word of warning: Nearly every software engineer has, at some point, been exploited by someone who used coding standards as a “power play.” Dogmatism over minutiae is the purview of the intellectually weak. Don’t be like them.
> - [ISO C++ Coding Standard FAQ](https://isocpp.org/wiki/faq/coding-standards#coding-std-wars)

Eine dogmatische Umsetzung finde ich genauso unsinnig wie den Verzicht auf einen *Style-Guide*. 

==TODO:==
- Was sollte ich (insbesondere bezüglich Änderungen in aktuellen C++ Standard) bei `Enums` berücksichtigen?
  - Siehe [C++ Core Guidelines - Enum](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#enum-enumerations)

### Andere Style-Guides
Ich habe mir folgende Style-Guides (grob) angeschaut und verworfen
- [Google](https://google.github.io/styleguide/cppguide.html)
  - Mir gefällt nicht die Benennung von *Attributen* mit `member_with_trailing_underscore_`.
  - Auch wenn ich das definierte Ziel *Be consistent with existing code* richtig finde und zu 100% unterstütze, möchte ich nicht die "alten Zöpfe" von Google in "meinen Style" übernehmen
- [JSF Air Vehicle C++ Coding Standard](https://stroustrup.com/JSF-AV-rules.pdf) - Nach [dieser Aussage](https://isocpp.org/wiki/faq/coding-standards#coding-std-wars) eine Empfehlung von Bjarne Stroustrup (für safety critical systems usw.)
  - Ist aus meiner Sicht wirklich für safety critical systems geschrieben (ist bei Flugzeugen wohl auch sinnvoll ;). Daher für mich allerdings nicht so richtig passend.
